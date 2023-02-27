FROM		debian:buster-slim

RUN			apt update && apt install -y nginx openssl															\
			&& mkdir -p /usr/share/nginx/www/gyepark.42.fr														\
			&& ln -s /etc/nginx/sites-available/gyepark.42.fr /etc/nginx/sites-enabled/gyepark.42.fr			\
			&& rm /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default							\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*														\
			&& openssl req																						\
				-new																							\
				-newkey rsa:2048																				\
				-x509																							\
				-sha256																							\
				-days 365																						\
				-subj /C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Gun/CN=gyepark/emailAddress=gyepark@student.42seoul.kr\
				# -config etc/ssl/example.conf -> to do this, COPY example.conf to /etc/ssl/example.conf first.
				-nodes																							\
				-out /etc/ssl/certs/gyepark.42.fr.crt															\
				-keyout /etc/ssl/certs/gyepark.42.fr.key

# placing COPY before RUN, there will be an error : Sub-process /usr/bin/dpkg returned an error code (1).
# apt update should be done first.
COPY		utils etc

EXPOSE		443

ENTRYPOINT	["nginx", "-g", "daemon off;"]