#include <stdio.h>
#include <iostream>
int main()
{
    signed char a = 127;
    unsigned char b = 0xff;
    unsigned char c = 0;
    a++;
    b++;
    c--;
    // 溢出后，触发回绕
    printf("a=%d\nb=%d\nc=%d\n",a,b,c);

    return 0;
}
