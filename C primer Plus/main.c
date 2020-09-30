//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//

#include <stdio.h>
void butler(void);

int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n");
    
    return 0;
}
void butler(void)
{
    printf("You rang, sir?\n");
}

