
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    double * ptd;
    int max;
    int number;
    int i = 0;
    
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1) {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc(max * sizeof (double));
    if (ptd == NULL) {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    puts("Enter the values (q to quit): ");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
        ++i;
    printf("Here are your %d entries:\n", number = i);
    for (i = 0;  i < number; i++) {
        printf("%7.2f", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd);
    
    return 0;
    
}
//除了可以使用malloc () 函数来分配内存, 还可以使用 calloc () 函数来申请内存
//calloc () 函数于malloc() 函数的区别就是 calloc () 函数比 malloc () 函数多了一个入参, 该入参为 ungicter int 类型的 起作用只是啦确定需要多少个 二参 所指定的内存区间.另为一点就是 通过 calloc () 函数所申请的内存是会被默认的将所申请的内存都初始化为 0 的.
//calloc () 函数所申请的内存空间的释放也是使用 free () 函数
//使用 malloc () 函数 又或是 calloc () 函数所申请的内存空间都是用free() 函数来释放,但是 free 所入参的指针可以于 依赖定义 malloc 或 calloc 是所非配的不同,但是所指向的内存地址是要相同的.

