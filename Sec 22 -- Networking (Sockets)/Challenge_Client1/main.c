#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_ONE 12345
#define PORT_TWO 54321

#define LOCAL_HOST "127.0.0.1"


//create a socket for communication
short socketCreate(void){
    short hSocket;
    printf("Created the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect with server

int socketConnect(int hSocket, int portNumb){
    int iRetval = -1;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr(LOCAL_HOST);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(portNumb);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}

int socketSend(int hSocket, int *value){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0){
        perror("Time out");
        exit(-1);
    }

    shortRetval = send(hSocket, value, sizeof(int), 0);
    return shortRetval;
}


int socketReceive(int hSocket, char *Rsp, short RvcSize){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0){
        perror("time out");
        exit(-1);
    }


    shortRetval = recv(hSocket, Rsp, RvcSize, 0);

    printf("Response: %s\n", Rsp);

    return shortRetval;

}


int main(int argc, char *argv[])
{
    printf("Client 1!\n");

    int hSocket = 0;
    int read_size = 0;
    int value = 0;
    struct sockaddr_in server;

    char server_reply[200] = {0};

    //create socket


    hSocket = socketCreate();

    if(hSocket == -1){
        fprintf(stderr, "Couldnt create socket\n");
        exit(1);
    }


    printf("Socket created!\n");

    //connect to remote server

    if(socketConnect(hSocket, PORT_ONE) < 0){
        fprintf(stderr, "Connect failed\n");
        exit(1);
    }


    printf("Successfully connected with server\n");

    //get instructions from server
    socketReceive(hSocket, server_reply, 200);
    printf("Server: %s\n", server_reply);

    //send int to server

    printf("Int value: ");
    scanf("%d", &value);

    //send data to server
    if(socketSend(hSocket, &value) < 0){
        fprintf(stderr, "send failed\n");
        exit(1);
    }

    //get confirmation from server

    socketReceive(hSocket, server_reply, 200);
    //printf("Server: %s\n", server_reply);

    close(hSocket);

    return 0;
}
