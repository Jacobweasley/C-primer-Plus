#include <stdio.h>
#define MONTHS 12

int main(void)
{
    int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    int index;
    
    for (index = 0; index < MONTHS; index++)
    printf("Month %2d has %d days.\n", index + 1, *(days + index));
    //这里并没有使用下标的方式来遍历数组,但是就在这样的写法等同于 下标 但是这样的写法并不如 下标明了
    //这样写的原理是 数组的名称就是数组中第一个项的内存地址,所以也就相当于指针 + 1的原理一样,其前面的 * 操作符是用来取值的.
    return 0;
}
