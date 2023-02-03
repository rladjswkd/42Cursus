FROM	debian:buster
RUN		apt update && apt install -y nginx openssl
# placing COPY before RUN, there will be an error : Sub-process /usr/bin/dpkg returned an error code (1).
# apt update should be done first.
COPY	conf /etc
RUN		openssl req\
			-new\
			-newkey rsa:2048\
			-x509\
			-sha256\
			-days 365\
			-nodes\
			-out /etc/ssl/certs/gyepark.42.fr.crt\
			-keyout /etc/ssl/certs/gyepark.42.fr.key
