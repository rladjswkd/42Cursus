FROM		debian:buster-slim

RUN			apt update && apt install -y vsftpd				\
			&& mkdir -p /usr/share/nginx/www/gyepark.42.fr	\
			&& mkdir -p /var/run/vsftpd/empty				\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*	

COPY		utils /

EXPOSE		21 50000-50010

ENTRYPOINT	["/usr/local/bin/adduser.sh"]