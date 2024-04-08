#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    //internet address family
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));

    return iRetval;
}


int main(int argc, char *argv[])
{
    printf("Creating a Server Socket\n");

    int socket_desc = 0;
    int sock = 0;
    int clientLen = 0;

    struct sockaddr_in client;

    //message buffer
    char client_message[200] = {'\0'};
    char message[100] = {0};

    const char *pMessage = "Hello from John's server";

    //create socket & return socket descripter
    socket_desc = socketCreate();
    if(socket_desc == -1){
        fprintf(stderr, "Could not create socket\n");
        exit(1);
    }


    printf("Socket created\n");

    //bind
    if(bindCreatedSocket(socket_desc) < 0){ //bind returns -1 for an error
        fprintf(stderr, "bind failed\n");
        exit(1);
    }

    printf("bind done\n");

    //listen
    listen(socket_desc, 3); //only allow 3 client to be waiting.

    //Accept incoming connections

    while(1){
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);


        //accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);

        //check if connection accepted
        if (sock < 0) {
            fprintf(stderr, "accept failed\n");
            exit(1);
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        //receive a message from the client
        if(recv(sock, client_message, 200, 0) < 0) {
            printf("recv failed\n");
            break;
        }

        printf("Client reply: %s\n", client_message);

        //check validity of client message
        // if(strncmp(pMessage, client_message, 5) == 0){
        //     strcpy(message, "Hi there !");
        // }

        if(strlen(client_message) > 1){
            strcpy(message,"Hello client!");
        }
        else{
            strcpy(message, "invalid message!");
        }

        //send some data
        if(send(sock, message, strlen(message), 0) < 0){
            fprintf(stderr, "Send failed\n");
            exit(1);
        }

        close(sock);
        sleep(1); //wait for a new connection

    }


    return 0;
}
