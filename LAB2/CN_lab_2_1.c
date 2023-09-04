#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int value = 0x21052158;
  unsigned char first_byte = (value & 0xFF);
  unsigned char last_byte = ((value >> 24) & 0xFF);

  printf("First byte: %02X\n", first_byte);
  printf("Last byte: %02X\n", last_byte);

  return 0;
}
