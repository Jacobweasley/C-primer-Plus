//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
#define SEC_PER_MIN 60
int main(void)
{
    int sec, min, left;
    
    printf("Convert seconds to minutes an seconds!\n");
    printf("Enter the number of seconds (<=0 to quit): \n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;
        left = sec % SEC_PER_MIN;
        printf("%d seconds is %d minutes, %d seconds.\n", sec, min , left );
        printf("Enter naxt value (<=0 to quit): \n");
        scanf("%d", &sec);
    }
    printf("Done!\n");
    
    return 0;
    
}
