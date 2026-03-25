#!/bin/bash
set -e

# Create FTP user if not exists
grep -q "${FTP_USER}" /etc/passwd || useradd -m -d /var/www/html -s /bin/bash "$FTP_USER"
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

# Set permissions
chown -R $FTP_USER:$FTP_USER /var/www/html

exec /usr/sbin/vsftpd /etc/vsftpd.conf
