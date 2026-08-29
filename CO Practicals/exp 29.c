#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer, item;
sem_t empty, full;

void *producer(void *arg) {
    item = 10;
    sem_wait(&empty);
    buffer = item;
    printf("Produced: %d\n", buffer);
    sem_post(&full);
    return NULL;
}

void *consumer(void *arg) {
    sem_wait(&full);
    printf("Consumed: %d\n", buffer);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
