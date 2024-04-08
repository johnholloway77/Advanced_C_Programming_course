#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LOCAL_HOST "127.0.0.1"

//Create a socket for server communication
short socketCreate(void){
    short hSocket;
    printf("Created the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect with server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345; //must match server port

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr(LOCAL_HOST);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

int socketSend(int hSocket, char *Rqst, short lenRqst){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //set 20 seconds timeout
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv) ) < 0){
        fprintf(stderr, "Time out\n");
        exit(-1);
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

int socketReceive(int hSocket, char *Rsp, short RvcSize){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //again, 20 second time out
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0){
        fprintf(stderr, "time out\n");
        exit(-1);
    }

    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response: %s\n", Rsp);

    return shortRetval;
}

int main(int argc, char *argv[])
{
    printf("Client Socket !\n");

    int hSocket = 0;
    int read_size = 0;
    struct sockaddr_in server;

    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    //create socket
    hSocket = socketCreate();

    if(hSocket == -1){
        fprintf(stderr, "Could not create socket\n");
        exit(1);
    }

    printf("Socket created!\n");

    //connect to remote server
    if(socketConnect(hSocket) < 0){
        fprintf(stderr, "Connect failed\n");
        exit(1);
    }

    printf("Successfully connected with server\n");
    printf("Enter the message: ");
    fgets(sendToServer, 100, stdin);

    //send the data to server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server response: %s\n", server_reply);

    close(hSocket);

    return 0;
}
