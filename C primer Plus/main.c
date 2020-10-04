//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
#define SPACE ' '
int main(void)
{
    char ch;
    
    ch = getchar();
    while(ch != '\n')
    {
        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
        ch = getchar();
    }
    putchar(ch);
    
    return 0;
}
