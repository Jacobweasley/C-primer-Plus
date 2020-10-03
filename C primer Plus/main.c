//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>

int main(void)
{
    int n = 3;
    
    while (n)
    {
        printf("%2d is true\n", n--);
    }
    printf("%2d is false\n", n);
    
    n = -3;
    while (n)
        printf("%2d is true\n", n++);
    printf("%2d is false\n", n);
    
    return 0;
    
}
