//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL 41
#define MAXAUTL 31

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};


int main(void)
{
    struct book library;
    
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    printf("Now anter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");
    
    return 0;
    
    
}


char * s_gets(char * st, int n )
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

//使用结构体定义的 变量的在内存中分配的空间是连续的，这种连续的代码有点像是 数组但是与数组不同的是， 在struct 中定义的数据的自由度是相对较高的 而数组中数据的类型在 该数组定义的时候就已经确定了，而在 struct 中 可以在定义的时候自己选择在该struct中 的数据类型， 以及数据的个数。
//在 C语言中的 struct 的结构体的也算是有实例化的， 是不过 他的实例化的语法与 swift 语言有些不一样。

// 在 C语言中 要想要将一个 struct 实例化的话就，同样需要使用 struct 在需要实例化的地方将需要的是实例化的名称写在对应的地方， 这样以后该 结构体的一个实例就是存在于该函数当中。

