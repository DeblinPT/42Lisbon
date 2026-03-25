FROM debian:oldstable

RUN apt-get update \
    && apt-get install -y \
    iproute2 \
    redis-server \
    gettext-base

COPY redis.conf /etc/redis/redis.conf

EXPOSE 6379

ENTRYPOINT ["/bin/sh", "-c", "envsubst < /etc/redis/redis.conf > /tmp/redis.conf && exec redis-server /tmp/redis.conf"]
