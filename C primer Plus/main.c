//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
#define PERIOD '.'
 int main(void)
{
    char ch;
    int charcount = 0;
    
    while ((ch = getchar()) != PERIOD) {
        if (ch != '"' && ch != '\'')
            charcount++;
    }
    printf("There are %d non-quote characters.\n", charcount);
    
    return 0;
    
}
