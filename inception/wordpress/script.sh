#!/bin/bash

echo "Waiting for Mariadb creation..."
sleep 5

cd /var/www/html
wp core download --allow-root

REDIS_PATH="/var/www/html"

until bash -lc ">/dev/tcp/mariadb/3306"; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
  done

if [ ! -e /var/www/html/wp-config.php ]; then
  wp config create --allow-root --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD \
      --dbhost=mariadb:3306
  wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --allow-root
  wp user create --allow-root --role=author $WP_USER $WP_EMAIL --user_pass=$WP_PASSWORD >> /log.txt

  if ! wp theme is-installed "amplitude" --allow-root --path="$REDIS_PATH"; then
    wp theme install "amplitude" --allow-root --path="$REDIS_PATH"
    echo "Theme Amplitude installed"
  fi
  if [ "${THEME_ACTIVATE:-true}" = "true" ]; then
    wp theme activate "amplitude" --allow-root --path="$REDIS_PATH"
    echo "Theme Amplitude activated"
  fi

  chown -R www-data:www-data /var/www/html || true
  find /var/www/html -type d -exec chmod 755 {} + || true
  find /var/www/html -type f -exec chmod 644 {} + || true
  chmod -R 775 /var/www/html/wp-content || true

  # Redis installation
  wp config set WP_REDIS_CLIENT --allow-root --path="$REDIS_PATH"
  wp config set WP_REDIS_HOST redis --allow-root --path="$REDIS_PATH"
  wp config set WP_REDIS_PORT 6379 --allow-root --path="$REDIS_PATH"

  wp plugin install redis-cache --allow-root --path="$REDIS_PATH"
  until bash -lc ">/dev/tcp/redis/6379"; do
    echo "Waiting for Redis to be ready..."
    sleep 1
  done
  
  wp plugin activate redis-cache --allow-root --path="$REDIS_PATH"
  wp redis enable --allow-root --path="$REDIS_PATH"
  echo "Redis enabled"
else
  echo "Fixing permissions for uploads and more..."
  chown -R www-data:www-data /var/www/html || true
  find /var/www/html -type d -exec chmod 755 {} + || true
  find /var/www/html -type f -exec chmod 644 {} + || true
  chmod -R 775 /var/www/html/wp-content || true
fi

if ! wp plugin is-active redis-cache --allow-root --path="$REDIS_PATH"; then
  echo "Enabling Redis cache plugin..."
  until bash -lc ">/dev/tcp/redis/6379"; do
    echo "Waiting for Redis to be ready..."
    sleep 1
  done
  wp plugin activate redis-cache --allow-root --path="$REDIS_PATH"
  wp redis enable --allow-root --path="$REDIS_PATH"
  echo "Redis enabled"
fi

SMTP_HOST="${MAILHOG_SMTP_HOST:-mailhog}"
SMTP_PORT="${MAILHOG_SMTP_PORT:-1025}"
MAIL_FROM="${MAIL_FROM:-no-reply@example.com}"
MAIL_FROM_NAME="${MAIL_FROM_NAME:-Inception}"

# Configure SMTP for development (MailHog) if enabled or host provided
if [ "${MAILHOG_ENABLED:-}" = "true" ] || [ -n "${MAILHOG_SMTP_HOST:-}" ]; then
  echo "Waiting for MailHog at $SMTP_HOST:$SMTP_PORT..."
  until bash -lc ">/dev/tcp/${SMTP_HOST}/${SMTP_PORT}"; do
    sleep 1
  done
  echo "MailHog reachable, configuring SMTP..."

  wp plugin install wp-mail-smtp --activate --allow-root --path="$REDIS_PATH" || true

  wp config set WPMS_ON true --type=constant --raw --allow-root --path="$REDIS_PATH"
  wp config set WPMS_MAILER smtp --type=constant --allow-root --path="$REDIS_PATH"
  wp config set WPMS_SMTP_HOST "$SMTP_HOST" --type=constant --allow-root --path="$REDIS_PATH"
  wp config set WPMS_SMTP_PORT "$SMTP_PORT" --type=constant --allow-root --path="$REDIS_PATH"
  wp config set WPMS_SSL none --type=constant --allow-root --path="$REDIS_PATH"
  wp config set WPMS_SMTP_AUTH false --type=constant --raw --allow-root --path="$REDIS_PATH"
  wp config set WPMS_SMTP_AUTOTLS false --type=constant --raw --allow-root --path="$REDIS_PATH"
  wp config set WPMS_MAIL_FROM "$MAIL_FROM" --type=constant --allow-root --path="$REDIS_PATH"
  wp config set WPMS_MAIL_FROM_NAME "$MAIL_FROM_NAME" --type=constant --allow-root --path="$REDIS_PATH"

  echo "MailHog / SMTP configured (host: $SMTP_HOST:$SMTP_PORT)"
fi

echo "Wordpress Ready!"
exec php-fpm8.2 -F