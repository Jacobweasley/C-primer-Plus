#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
#define HALT ""
void stsrt(char * strings[], int num);
char * s_gets(char * st, int n);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;
    
    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < (LIM - 1) && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
        //所以这里的 while 循环的判断条件的意思为,只要有s_gets()函数没有读取到任何的字符的时候,并且就算是只读取到了一个 \n 在文件的结尾,也算是读取到了一句字符串所以,s_gets()函数也是会返回第一参数的地址的,所以也算是输入成功了
        //但是在 s_gets 函数中还是有一个if 语句里面包装了一个功能就是讲函数内所有的\n 都装换成 \0 又因为在实际情况上,所有的字符串都是读取到 \0 就结尾了,就算是后面还有 \0 无关紧要了,所以造成的现象的是,想要想这个 while循环推出的关键就是就是输入一行只有回车键字符的字符串.又或者是达到输入行数的上限.
        
        //但是在实际情况下这行之输入了\n的行没有任何的实际作用.
    {
        ptstr[ct] = input[ct];
        ct++;//这里的ct 在最后的时候总会添加了一行空行(即里面只有\n 字符的无用行).
        //所以在后面检查字符串字母的排序中,这行为了推出循环而添加的空行就没有用了.
    }
    stsrt(ptstr, ct);
    
    puts("\nHere's the sorted listed list: \n");
    for (k = 0; k < ct ; k++)
    puts(ptstr[k]);
    return 0;
}

void stsrt(char * strings[], int num)
{
    char * temp;
    int top, seek;
    
    for (top = 0; top < num - 1; top++)
    //在这个循环当中,之所以要将入参的 ct - 1 就是因为,上面讲到的空行的原因,又因为ct 是从0开始数的所以就算是一开始定义的 LIM 常数 = 20 也就是实际能够使用下标ct 只有 0-19的空间,在上面的 while 循环当中,虽然限定了,ct 必须要小于 LIM 但是如果真的 ct 已经从0 迭代到了19的时候,ct == 19 的情况下,还是会执行 while的代码,只要一执行,ct 就会 + 1
    //所以在实际情况下ct 是有可能达到 20的,但是这里的for循环遍历如果直接使用 ct 的值而不加以处理的话就会有访问溢出的风险.
    //那为什么不在上面的while循环里面就直接 -1 来限制 ct 无法进行第19次循环呢,这样也就更加清晰,更加安全啊.
    //不要忘了,前面我们讲到的,要想要 while 循环 break 的方法只有两个,一个就是 ct迭代越界,还有一个是 输入一行只有 \n 字符的字符串. 这样剩下的就是取舍问题了,因为用户有可能真的输入了 20句字符串,输入到20句字符串的时候,ct 正好迭代到 19.如果在这个时候 while 是限制在 ct < (LIM - 1) 的话.虽然 while 还是正常的推出,但是用户就输入不了第20行了.
    //这里的 ct - 1 就是为了解决 ct 迭代到 19 也就是用户输入到第二十行的时候,导致的 ct 迭代到20 的问题,因为这里 用的是 < 号所以即使 num (即ct) 不减1,top也不会迭代的 20 但是问题的下面的 top + 1 会,所以这里就要减掉1
    
    for (seek = top + 1; seek < num; seek++) {
        //这里所使用到的排序算法是冒泡排序算法,
        if (strcmp(strings[top], strings[seek]) > 0) {
            temp = strings[top];
            strings[top] = strings[seek];
            strings[seek] = temp;
        }
    }
}
char * s_gets(char * st, int n )
{
    char * ret_val;
    int i = 0;
    
    ret_val = fgets(st, n, stdin);
    //这里的的fgets()函数,在正常读取的话会返回一个与第一入参一样的地址,但如果函数读取到文件的结尾,那么该函数就会返回一个 NULL 的值,这里所说的文件结尾应该是指的是缓冲区的文件吧,因为fgets 函数直接作用的 是 stdin 标准输入文件啊,而标准输入文件就是 指输入的缓冲区.
    if (ret_val)
        //所以这里的if 语句判断的就是如果该返回值是非 NULL 的就会执行以下的代码.
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
    //在这里如果返回 NULL 就只有两种可能,因为 fgets() 函数只有在读取到了文件的结尾,以及没有读取到任何字符的情况下才会返回 NULL
}
