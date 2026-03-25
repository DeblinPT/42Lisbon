FROM debian:oldstable

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        apache2 \
        php \
        php-mysqli \
        php-pdo \
        php-mysql \
        wget \
        ca-certificates

WORKDIR /var/www/html

# Download Adminer
RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O adminer.php

# Configure Apache to serve Adminer as the default page
RUN echo "DirectoryIndex adminer.php" > /etc/apache2/conf-available/adminer.conf \
    && a2enconf adminer

EXPOSE 8081

CMD ["/usr/sbin/apache2ctl", "-D", "FOREGROUND"]
