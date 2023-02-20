#!/bin/bash

# start mysql daemon temporarily in background
service mysql start

# improving security
mysql_secure_installation << HEREDOC

y
$MYSQL_ROOT_PASSWORD
$MYSQL_ROOT_PASSWORD
y
y
y
y
HEREDOC

mysql -e "CREATE DATABASE ${MYSQL_DATABASE};"
mysql -e "CREATE USER '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -e "FLUSH PRIVILEGES;"
# without sleep, service mysql stop prints messages like below.
# [....] Stopping MariaDB database server: mysqld/usr/bin/mysqladmin: connect to server at 'localhost' failed
# error: 'Can't connect to local MySQL server through socket '/var/run/mysqld/mysqld.sock' (2)'
# Check that mysqld is running and that the socket: '/var/run/mysqld/mysqld.sock' exists!
# . ok
sleep .5

service mysql stop

exec "$@"`