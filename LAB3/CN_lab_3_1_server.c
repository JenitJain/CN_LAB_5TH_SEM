#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  int port = 63725;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    printf("Error in creating server socket\n");
    exit(1);
  } else {
    printf("Server socket created\n");
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(port);

  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    printf("Error in binding server socket\n");
    exit(1);
  } else {
    printf("Server socket binding done properly with Port:%d\n",port);
  }

  listen(server_socket, 5);

  client_socket = accept(server_socket, (struct sockaddr *) &client_address, sizeof(client_address));
  if (client_socket == -1) {
    printf("Error in accepting client socket\n");
    exit(1);
  } else {
    printf("Client socket accepted\n");
  }

  char message[100];
  read(client_socket, message, sizeof(message));
  printf("Message from client: %s\n", message);

  write(client_socket, "Hello client!", sizeof("Hello client!"));

  close(server_socket);
  close(client_socket);

  return 0;
}

