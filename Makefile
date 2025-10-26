all: producer consumer

producer: producer.c shared_mem.c
    gcc -o producer producer.c shared_mem.c -lrt -pthread

consumer: consumer.c shared_mem.c
    gcc -o consumer consumer.c shared_mem.c -lrt -pthread

clean:
    rm -f producer consumer
