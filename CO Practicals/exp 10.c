#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main()
{
    key_t key = 1234;

    int msgid = msgget(key,0666|IPC_CREAT);

    message.msg_type = 1;

    printf("Enter message: ");
    scanf("%s",message.msg_text);

    msgsnd(msgid,&message,sizeof(message),0);

    printf("Message Sent: %s\n",message.msg_text);

    return 0;
}
