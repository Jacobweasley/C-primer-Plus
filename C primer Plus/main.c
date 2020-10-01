//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//

#include <stdio.h>

int main(void)
{
    int num = 1;
    while (num < 21){
        printf("%4d %6d\n", num, num * num);
        num = num + 1;
    }
    
    return 0;
    
}
