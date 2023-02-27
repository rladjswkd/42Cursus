#!/bin/bash

adduser ${FTP_USER} << EOF
${FTP_PASSWORD}
${FTP_PASSWORD}





Y
EOF

exec vsftpd /etc/vsftpd.conf