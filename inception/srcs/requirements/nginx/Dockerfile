FROM		debian:buster-slim

RUN			apt update && apt install -y nginx openssl	\
			&& apt-get clean && rm -rf /var/lib/apt/lists/*

# placing COPY before RUN, there will be an error : Sub-process /usr/bin/dpkg returned an error code (1).
# apt update should be done first.
COPY		conf etc

RUN			openssl req\
				-new\
				-newkey rsa:2048\
				-x509\
				-sha256\
				-days 365\
				-subj /C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Gun/CN=gyepark/emailAddress=gyepark@student.42seoul.kr\
				# -config etc/ssl/example.conf\
				-nodes\
				-out /etc/ssl/certs/gyepark.42.fr.crt\
				-keyout /etc/ssl/certs/gyepark.42.fr.key
				
ENTRYPOINT	["nginx", "-g", "daemon off;"]