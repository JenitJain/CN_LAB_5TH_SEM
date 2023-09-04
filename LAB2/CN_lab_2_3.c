#include <stdio.h>
#include <stdint.h>
struct packet
{
    char a1;
    char a2[2];
    char a3;
};
int main(){
    unsigned int value = 0x26012105;
    struct packet data;
    data.a1 = (value & 0xFF);
    data.a2[0] = ((value >> 8) & 0xFF);
    data.a2[1] = ((value >> 16) & 0xFF);
    data.a3 = ((value >> 24) & 0xFF);
    printf("Value = %08x\n", value);
    printf("Content of the structure:\n");
    printf("a1: %02X\n", data.a1);
    printf("a2[0]: %02X\n", data.a2[0]);
    printf("a2[1]: %02X\n", data.a2[1]);
    printf("a3: %02X\n", data.a3);
    return 0;
}
