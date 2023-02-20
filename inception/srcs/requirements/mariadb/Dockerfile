FROM		debian:buster-slim

RUN			apt update && apt install -y mariadb-server-10.3 	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*		\
			&& mkdir -p /run/mysqld								\
			&& find /run/mysqld ! -user mysql -exec chown --no-dereference mysql "{}" +

COPY		tools /

EXPOSE		3306			

ENTRYPOINT	["/usr/local/bin/entrypoint.sh"]

CMD			["mysqld"]