#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 81
void Toupper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT];
    char * find;
    
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    //这里有点危险,因为如果是输入了的是正好有LIMIT这么多的字符呢,就会产生一个没有\0 的字符数组.
    find = strchr(line, '\n');
    if (find)
        *find = '\0';
    Toupper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
    
    return 0;
}

void Toupper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}


int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    
    return ct;
}




