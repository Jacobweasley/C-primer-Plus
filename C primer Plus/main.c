#include <stdio.h>
#define SRTLEN 3
int main(void)
{
    char words[SRTLEN];
    
    puts("Enter a string, please.");
    gets(words);
    printf("Your string twice;\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");
    
    return 0;
}

