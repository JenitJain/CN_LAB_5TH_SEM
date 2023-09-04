#include <stdio.h>
void swap (int *A, int *B)
{
int temp = *A;
*A = *B;
*B = temp;
}

int main()
{
int x=5, y=10;
printf("Before Swapping: x=%d, y%d\n",x,y);
swap(&x, &y);
printf("After swapping: x=%d, y=%d\n",x,y);
return 0;
}

