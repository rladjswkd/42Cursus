FROM		debian:buster-slim

RUN			apt update && apt install -y mariadb-server-10.3 							\
			&& mkdir -p /run/mysqld														\
			&& find /run/mysqld ! -user mysql -exec chown --no-dereference mysql "{}" +	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY		utils /

RUN			chmod 644 /etc/mysql/my.cnf													\
			&& chmod 100 /usr/local/bin/entrypoint.sh

EXPOSE		3306			

ENTRYPOINT	["/usr/local/bin/entrypoint.sh"]

CMD			["mysqld"]