#!/bin/bash

# SQL - SET PASSWORD for root to change its plugin into mysql_native_password is not recommended.
# Debian assumes the use of unix_socket by default. 
# Therefore, if you force the use of mysql_native_password, permission errors will occur when running commands such as 'service mysql start, status, stop.

# start mysql daemon temporarily in background
service mysql start

# create database and user
mysql -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};"
mysql -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

# improving security
mysql -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${MYSQL_ROOT_PASSWORD}');"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED VIA mysql_native_password;"

mysql_secure_installation << HEREDOC
$MYSQL_ROOT_PASSWORD
n
y
y
y
y
HEREDOC

# without sleep, service mysql stop prints messages like below.
# [....] Stopping MariaDB database server: mysqld/usr/bin/mysqladmin: connect to server at 'localhost' failed
# error: 'Can't connect to local MySQL server through socket '/var/run/mysqld/mysqld.sock' (2)'
# Check that mysqld is running and that the socket: '/var/run/mysqld/mysqld.sock' exists!
# . ok
sleep .5

kill -9 $(ps aux | grep 'mysqld'| awk '{print $2}')

exec "$@"