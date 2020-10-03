//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    int status;
    
    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    status = scanf("%ld", &num);
    while (status == 1)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);//在该表达式中, scanf 语句使有返回值的,也就是说,要是 scanf 函数正确的接收了一个整形,则会正确赋值给 num 并且  return 0.以使 该 while 循环继续
        
        
    }
    printf("Those integers sum to %ld.\n", sum);
    
    return 0;
}


