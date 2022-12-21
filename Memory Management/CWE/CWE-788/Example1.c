/*In the following C/C++ example the method processMessageFromSocket() will get a message from a socket,
 placed into a buffer, and will parse the contents of the buffer into a structure that contains the message length and the message body.
  A for loop is used to copy the message body into a local character string which will be passed to another method for processing.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*Sizes to generate the error*/
#define BUFFER_SIZE 20
#define SOCMSGLEN   20
#define MESSAGE_SIZE 10

/*Message structure*/
struct ExMessage {
    int msgLength;
    char* msgBody;
    };

/*Fn simulates getting message from buffer and placed it in socket*/
int getMessage(int socket_p, char * buff, int buffsize)
{
    char fromsocket [buffsize];
    int index;
    for(index=0;index<SOCMSGLEN;index++)
    {
        fromsocket[index]= 'H';
        buff[index] = fromsocket[index];
    }
    
    return 1;
}

/*Fn simulates proccessing the message*/
int processMessage(char * message)
{
    return true;
}

int processMessageFromSocket(int socket) {
    int success;

    char buffer[BUFFER_SIZE];
    char message[MESSAGE_SIZE];

    // get message from socket and store into buffer
    //Ignoring possibliity that buffer > BUFFER_SIZE

    if (getMessage(socket, buffer, BUFFER_SIZE) > 0) {

        // place contents of the buffer into message structure
        struct ExMessage msg ;
        msg.msgLength = SOCMSGLEN;
        msg.msgBody = (char*)malloc (SOCMSGLEN);

        int index;
        for (index = 0; index < SOCMSGLEN; index++) {
            msg.msgBody[index]= buffer[index];
        }
        /*show temp Message buffer size */
        printf("Message for proccessing buffer size = %d\n",MESSAGE_SIZE);

        // copy message body into string for processing
        for (index = 0; index < msg.msgLength; index++) {
            message[index] = msg.msgBody[index];
            /*Weakness : Here if message buffer size < socket message body length the loop will access out of bound*/
            printf("Current index to access message buffer : %d\n",index);
        }
        message[index] = '\0';

        // process message
        success = processMessage(message); 
    }
    return success;
}

int main ()
{
    processMessageFromSocket(8888);
}