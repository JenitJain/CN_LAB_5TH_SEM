#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int client_socket;
  struct sockaddr_in server_address;
  int port = 63725;

  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    printf("Error in creating client socket\n");
    exit(1);
  } else {
    printf("Client socket created\n");
  }

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(port);

  if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    printf("Error in connecting to server\n");
    exit(1);
  } else {
    printf("Connected to server\n");
  }

  char message[100];
  printf("Enter message: ");
  scanf("%s", message);

  write(client_socket, message, sizeof(message));

  read(client_socket, message, sizeof(message));
  printf("Message from server: %s\n", message);

  close(client_socket);

  return 0;
}

