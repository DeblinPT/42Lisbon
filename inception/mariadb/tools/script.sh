#!/bin/bash

chown -R mysql:mysql /var/lib/mysql /run/mysqld

# Initialize the data directory if needed
if [ ! -d /var/lib/mysql/mysql ]; then
	echo "Initializing MariaDB data directory..."
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

mysqld_safe --skip-networking &

for i in {1..30}; do
	if [ -S /run/mysqld/mysqld.sock ]; then
		break
	fi
	echo "Waiting for MariaDB socket... ($i)"
	sleep 1
done

sleep 10

mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
echo "step 1 done"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
echo "step 2 done"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
echo "step 3 done"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
echo "step 4 done"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"
echo "all steps done"

sleep 3
mysqladmin -uroot -p"${MYSQL_ROOT_PASSWORD}" shutdown

exec mysqld_safe --bind-address=0.0.0.0

cat /var/log/mysql/error.log || cat /var/log/mysqld.log || true

echo "maria over and out"