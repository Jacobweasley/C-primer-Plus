#include <stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short * pit;
    short index;
    double bills[SIZE];
    double * ptf;
    pit = dates;
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    //这个打印语句实际上只是单纯的打印字符串的语句而已
    for (index = 0; index < SIZE; index++)
    printf("pointers + %d: %10p %10p\n", index, pit + index, ptf + index);
    
    return 0;
}

