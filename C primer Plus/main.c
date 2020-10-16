#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int dice, roll;
    int sides;
    int status;
    
    srand((unsigned int) time(0));
    //调用了 srand() 函数, 传入 time(0) 获取系统时间的函数作为随机数产生的种子
    //其中的 time 函数所返回的是一种 特殊的 time_t 类型的返回值.
    //要想使用 就需要使用强制类型转换.转换成正整形的.
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0){
        //通过调用  scanf 来将用户输入 的整形 存储于 地址  sides 中
        printf("How many dice?\n");
        if ((status =  scanf("%d", &dice)) != 1)
            //询问用户, 再将用户输入的整形存储在 status 中,在获取用户的输入的过程中还检查用户是否按要求输入了一个整形的数字.
        {
            if (status == EOF)
                //可以检测是否 status 是否一定到了尾部,意思该是检测 在上面的语句当中录入的 scanf 是否成功,是否符合要求.否则将会推出循环.
                break;
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n') {
                    continue;
                }
                printf("How many sides? Enter 0 to stop.\n");
                continue;
            }
            
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
        
    }
    printf("The rollem() function was called %d time.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
    
    return 0;
    
}

