#define MSG "I'm special"

#include <stdio.h>
int main(void)
{
    char ar[] = MSG;
    const char *pt = MSG;
    printf("address of \"I'm special\": %p \n", "I'm special");
    printf("                address ar: %p\n", ar);
    printf("                address pt: %p\n", pt);
    printf("            address of MSG: %p\n", MSG);
    printf("address of \"I'm special\": %p  \n", "I'm special");
    
    return 0;
}

//在 C语言中,通常,师傅穿都作为可执行文件的一部分存储在数据段中,当吧程序载入内存时,也会在符程序中的字符串.字符传存储在静态存储区汇总.但是, 程序在开始运行时才会为该数组分配内存,此时,才将字符串拷贝到数组中,.此时字符串有两个副本,
//一个时在静态内存中的字符串字面量, 另一个是存储在 ar1 数组中的字符串.
//瓷釉, 编译器便把数组名 ar1 识别为该数组元素地址的(&ar1[0])的别名. 这里关键要理解,在数组形式中,ar1 是地址常量.不能更改 ar1, 如果改变了 ar1 , 则意味着干改变了数组存储的位置(即地址). 可以进行类似 ar1 + 1 这样的操作, 标识数组的下一个元素.
//但是不允许 ++ar1 这样的操作. 递增运算符只能用于变量前(或概括地说, 只能用于可修改的左值).
//我猜这里的左值的意思就是一个变量的名字吧,而 一个数组的名字并不是变量所以不可以用递增操作符.

