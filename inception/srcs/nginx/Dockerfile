FROM debian:bullseye

RUN apt update -y && apt upgrade -y && apt install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl && openssl req -x509 -nodes -days 365 -keyout /etc/nginx/ssl/inception.key -out /etc/nginx/ssl/inception.crt -subj "/CN=${MYSQL_DATABASE}"

RUN mkdir -p /var/www/wordpress /var/run/nginx && chmod 755 /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress && mkdir -p /var/www/bonus

COPY config/nginx.conf /etc/nginx/nginx.conf

COPY bonus/index.html /var/www/bonus/index.html
CMD ["nginx", "-g", "daemon off;"]