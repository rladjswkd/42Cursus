FROM		debian:buster-slim

RUN     	apt update																						\
			&& apt install -y php7.3 php7.3-fpm php7.3-mysql php7.3-redis									\
			&& mkdir -p /run/php																			\
			&& mkdir -p /usr/share/nginx/www/gyepark.42.fr													\
			&& apt install -y wget																			\
			&& wget https://wordpress.org/latest.tar.gz														\
			&& tar -xf latest.tar.gz --directory /usr/share/nginx/www/gyepark.42.fr	--strip-components 1	\
			&& rm -rf latest.tar.gz																			\
			&& chown -R www-data:www-data /usr/share/nginx/www/gyepark.42.fr/wp-content						\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*	

COPY		conf /

EXPOSE		9000

ENTRYPOINT	["php-fpm7.3", "--nodaemonize"]