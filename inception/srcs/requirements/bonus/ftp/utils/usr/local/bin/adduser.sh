#!/bin/bash

adduser ${FTP_USER} << EOF
${FTP_PASSWORD}
${FTP_PASSWORD}





Y
EOF

# upload is enabled with chown, or disabled.
# chown -R ${FTP_USER} /usr/share/nginx/www/gyepark.42.fr
chmod 777 /usr/share/nginx/www/gyepark.42.fr
exec vsftpd /etc/vsftpd.conf
