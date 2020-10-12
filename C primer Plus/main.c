#include <stdio.h>
#define SLEN 40
#define LIM 5
int main(void)
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalent[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", "Watching television",
        "Mailing letters", "Reading email"
    };
    int i;
    
    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++)
    printf("%-3s  %-25s\n", mytalents[i], yourtalent[i]);
    
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalent));
    
    return 0;
    
}
