//
//  main.c
//  C primer Plus
//
//  Created by 大娘 on 2020/9/30.
//
#include <stdio.h>
int main(void)
{
    const int FREEZING = 0;
    float temperatre;
    int cold_days = 0;
    int all_days = 0;
    
    printf("Enter the list of daily low temperatures.\n");
    printf("Use Celsius, and enter q to quit.\n");
    while (scanf("%f", &temperatre) == 1)
    {
        all_days++;
        if (temperatre < FREEZING)
            cold_days++;
    }
    if (all_days != 0)
        printf("%d days total: %.1f%% were below freezing.\n", all_days, 100.0 * (float) cold_days / all_days);
    if (all_days == 0)
    {
        printf("No data entered!\n");
    }
    
}
