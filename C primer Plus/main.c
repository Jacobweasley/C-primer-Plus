//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//


#include <stdio.h>

int main(void)
{
    int n = 0;
    size_t intsize;
    //这里的 size_t 返回的是一种无符号的返回值类型的整形
    //这里使用到的是 typedef 的机制,即将 C语言中原本就带有的类型起别名.
    //在当前的使用环境中,该 size_t 的就就相当于 unsigned int .
    intsize = sizeof  (int);
    
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n , sizeof n , intsize);
    
    return 0;
    
    
}
