FROM	debian:buster-slim

RUN     apt update										\
		&& apt install -y php-fpm						\
		&& mkdir -p /run/php							\
		&& apt install -y wget							\
		&& wget https://wordpress.org/latest.tar.gz		\
		&& tar -xzvf latest.tar.gz						\
		&& rm -rf latest.tar.gz							\
		&& apt-get clean && rm -rf /var/lib/apt/lists/*	
