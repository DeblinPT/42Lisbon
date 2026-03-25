FROM debian:stable-slim

RUN apt-get update && apt-get install -y \
    vsftpd \
    openssl \
    iproute2

COPY vsftpd.conf /etc/vsftpd.conf
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Generate SSL certificate and key for FTPS
RUN openssl req -x509 -nodes -days 365 \
    -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=Student/CN=localhost" \
    -newkey rsa:2048 \
    -keyout /etc/ssl/private/vsftpd.key \
    -out /etc/ssl/private/vsftpd.crt

EXPOSE 21 21100-21110

CMD ["/entrypoint.sh"]
