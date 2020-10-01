//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//

#include <stdio.h>
#define ADJUST 7.3
int main(void)
{
    const double SCALE = 0.333;
    double shoe, foot;
    
    printf("Shoe size (men's)   foot length\n");
    shoe = 3.0;
    while (shoe < 18.5) {
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f inches\n", shoe, foot);
        shoe = shoe + 1.0;
    }
    //这里使用了 while 循环,即在变量 shoe 没有大于 18.5的情况下持续运行该循环
    //在该循环中,先是算出该鞋码对应的大小的脚的尺寸.
    //每次村还都是将对应的鞋码与脚的大小,打印出来.
    //在每次循环中,shoe 变量自加 1 .
    printf("If the shoe fits, wear it. \n");
    
    return 0;
}


