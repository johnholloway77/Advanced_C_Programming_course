/*
 Challenge: create server and two clients
    Client 1 will send an integer to the server process
    the server will decrement the number and send the result to clinet 2
    the server should print both the value it receives and the value that it
 sends Client2 prints the number it receives All three processes will terminate
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_ONE 12345
#define PORT_TWO 54321

short socketCreate(void) {
    short hSocket;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket, int portNumb) {
    int iRetval = -1;
    //    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    // internet address family
    remote.sin_family = AF_INET;

    // any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(portNumb); // local port

    // bind this baby!
    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));

    return iRetval;
}

int main(int argc, char *argv[]) {
    printf("Server client!\n");

    int socket_desc1 = 0;
    int socket_desc2 = 0;
    int sock1 = 0;
    int sock2 = 0;
    int clientLen = 0;

    struct sockaddr_in client1;
    struct sockaddr_in client2;

    // messages and int values
    char message[100] = {0};
    int value = 0;

    const char *pMessage = "Hello from server program";

    // create socket and return socket descripter
    socket_desc1 = socketCreate();
    if (socket_desc1 == -1) {
        perror("Couldnt create socket1\n");
        exit(1);
    }

    printf("Socket1 Created!\n");

    // create socket and return socket descripter
    socket_desc2 = socketCreate();
    if (socket_desc2 == -1) {
        perror("Couldnt create socket2\n");
        exit(1);
    }

    printf("Socket2 Created!\n");

    // bind socket
    if (bindCreatedSocket(socket_desc1, PORT_ONE) < 0) {
        perror("Bind failed!");
        exit(1);
    }
    printf("socket1 bound\n");

    if (bindCreatedSocket(socket_desc2, PORT_TWO) < 0) {
        perror("Socket2 Bind failed!");
        exit(1);
    }

    printf("socket2 bound\n");

    listen(socket_desc1, 1);
    printf("Waiting for client1 on port %d\n", PORT_ONE);
    listen(socket_desc2, 1);
    printf("Waiting for client2 on port %d\n", PORT_TWO);


    clientLen = sizeof(struct sockaddr_in);

    sock1 = accept(socket_desc1, (struct sockaddr *)&client1,
                   (socklen_t *)&clientLen);
    if (sock1 < 0) {
        perror("sock1 accept failed");
        exit(1);
    } else {
        printf("Connected to client 1\n");
    }

    sock2 = accept(socket_desc2, (struct sockaddr *)&client2,
                   (socklen_t *)&clientLen);
    if (sock2 < 0) {
        perror("Sock2 accept failed!");
        exit(1);
    } else {
        printf("Connected to client 2\n");
    }

    //sprintf(message, "currently waiting for int from client 1");

    strlcpy(message, "currently waiting for int from client 1", sizeof(message));

    if(send(sock2, message, strlen(message), 0) < 0){
        perror("send to sock2 failed");
        exit(1);
    }

    strlcpy(message, "Please enter an int value", sizeof(message));

    if(send(sock1, message, strlen(message), 0) < 0){
        perror("send to sock1 failed");
        exit(1);
    }


    if(recv(sock1, &value, sizeof(int), 0) < 0){
        perror("error receiving int from client");
        exit(1);
    }

    value--;

    sprintf(message, "Integer received: %d After decrementing: %d", value + 1, value);

    printf("\n%s\n", message);

    if(send(sock1, message, strlen(message), 0) < 0){
        perror("send to sock1 failed");
        exit(1);
    }

    if(send(sock2, message, strlen(message), 0) < 0){
        perror("send to sock2 failed");
        exit(1);
    }

    close(sock1);
    close(sock2);


    sleep(2);
    printf("That's all folks!\n");


    return 0;
}
