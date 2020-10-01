//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//

#include <stdio.h>

#define ADJUST 7.31

int main(void)
{
    const double SCALE = 0.333;
    double shoe, foot;
    
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe size (men's)  foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
    //在 %f 中的 f 前添加 0.2 表示精确到小数点的后两位,而如果在 f 前添加大于1 的数的话就表示在前面预留多少个字符位置
    return 0;
}

