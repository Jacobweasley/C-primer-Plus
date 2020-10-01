//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//

#include <stdio.h>
#include <string.h>

#define DENSITY 62.4
int main()
{
    float weight, volume;
    int size, letters;
    char name[40];
    
    printf("Hi! What's your first name?\n");
    scanf("%s", name);//在scanf 输入字符串时并不用使用 & 取址操作符
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);//使用 strlen()来获取字符串的长度
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cunbic feet. \n", name , volume);
    printf("Also, your first name has %d letters, \n", letters);
    printf("and we have %d bytes to store it. \n", size);
    
    return 0;
    
}
