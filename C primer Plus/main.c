//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30



#include <stdio.h>

void to_bingary (unsigned long n);

int main(void)
{
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1) {
        printf("Binary equivalent: ");
        to_bingary(number);
        putchar('\n');
        printf("Enter an integer (q to quit): \n");
        
    }
    printf("Done.\n");
    
    return 0;
}

void to_bingary(unsigned long n)
{
    int r;
    
    r = n % 2;
    if (n >= 2)
        to_bingary(n / 2);
    putchar(r == 0 ? '0' : '1');
    
    return;
}



