
#include <stdio.h>
#include <stdint.h>
struct packet
{
    char a1;
    char a2[2];
    char a3;
};
int main()
{
    unsigned int original_value = 0x21052736;
    struct packet data;
    data.a1 = (original_value & 0xFF);
    data.a2[0] = ((original_value >> 8) & 0xFF);
    data.a2[1] = ((original_value >> 16) & 0xFF);
    data.a3 = ((original_value >> 24) & 0xFF);
    printf("Original Value = %08X\n", original_value);
    printf("Content of the structure:\n");
    printf("a1: %02X\n", data.a1);
    printf("a2[0]: %02X\n", data.a2[0]);
    printf("a2[1]: %02X\n", data.a2[1]);
    printf("a3: %02X\n", data.a3);
    unsigned int regenerated_value = 0;
    regenerated_value |= (unsigned int)data.a1;
    regenerated_value |= ((unsigned int)data.a2[0] << 8);
    regenerated_value |= ((unsigned int)data.a2[1] << 16);
    regenerated_value |= ((unsigned int)data.a3 << 24);
    printf("Regenerated Original Number: 0x%08X\n", regenerated_value);
    return 0;
}
