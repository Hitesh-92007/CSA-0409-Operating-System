#include<stdio.h>
#include<pthread.h>

void *printMessage(void *arg)
{
    printf("Thread is running...\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid,NULL,printMessage,NULL);

    pthread_join(tid,NULL);

    printf("Thread execution completed.\n");

    return 0;
}
