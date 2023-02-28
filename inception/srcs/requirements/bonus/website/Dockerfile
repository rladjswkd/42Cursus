FROM    debian:buster-slim

RUN     apt update -y && apt install -y nginx

COPY    utils /var/www/html/

CMD     ["nginx", "-g", "daemon off;"]