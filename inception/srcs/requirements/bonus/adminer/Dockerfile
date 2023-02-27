FROM		debian:buster-slim

RUN			apt update && apt install -y curl php7.3-fpm php7.3-mysql																					\
			&& mkdir -p /run/php																														\
			&& mkdir -p /usr/share/nginx/www/gyepark.42.fr																								\
			&& curl -fsSL https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -o /usr/share/nginx/www/gyepark.42.fr/adminer.php	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY		utils /

EXPOSE		8000

ENTRYPOINT	["php-fpm7.3", "--nodaemonize"]