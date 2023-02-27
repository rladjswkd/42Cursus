FROM		debian:buster-slim

RUN			apt update && apt install -y lsb-release redis	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*	

COPY		utils /

EXPOSE		6379

ENTRYPOINT	["redis-server", "/etc/redis/bonus.conf"]