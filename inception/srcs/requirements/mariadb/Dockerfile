FROM		debian:buster-slim

RUN			apt update && apt install -y mariadb-server 	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*	\
			&& mkdir -p /run/mysqld							\
			&& find /run/mysqld ! -user mysql -exec chown --no-dereference mysql "{}" +

EXPOSE		3306			

ENTRYPOINT	mysqld