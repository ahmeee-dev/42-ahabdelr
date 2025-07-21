FROM debian:bullseye

ARG DOMAIN_NAME

RUN echo "DOMAIN_NAME is: '${DOMAIN_NAME}'"

RUN apt update -y && apt upgrade -y && apt install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl && openssl req -x509 -nodes -days 365 -keyout /etc/nginx/ssl/inception.key -out /etc/nginx/ssl/inception.crt -subj "/CN=ahabdelr.42.fr"

RUN mkdir -p /var/www/wordpress /var/run/nginx && chmod 755 /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress

COPY config/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off"]