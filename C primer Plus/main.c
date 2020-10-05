//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
            putchar(ch + 1);
        else
            putchar(ch);
    }
    putchar(ch);
    
    return 0;
}

