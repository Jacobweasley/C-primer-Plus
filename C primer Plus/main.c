#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10
#define TOTLE 12

struct seats {
    unsigned int seatnumber;
    bool book;
    char firstname[LEN];
    char lastname[LEN];
};

struct seats plane[TOTLE];
void emptytheplane(int);
void showseats(void);
char showmanule(void);
char * s_gets(char * st, int n);
void showemptyseat(void);
void showinformationofemptyseat(void);
void showinformationofunemptyseat(void);
void bookingseat(void);
void unbookingseat(void);
void exitprogarm(void);
void show(void(*fp)(char *), char * str);

int main(void)
{
    char anser;
    void(*pfun)(void) = NULL;
    emptytheplane(0);
    showseats();
    do {
        anser = showmanule();
        switch (anser) {
                case 'a': pfun = showemptyseat;  break;
                case 'b': pfun = showinformationofemptyseat; break;
                case 'c': pfun = showinformationofunemptyseat; break;
                case 'd': pfun = bookingseat; break;
                case 'e': pfun = unbookingseat; break;
                case 'i': pfun = showseats; break;
                case 'f': break;
        }
        pfun();
    } while (anser != 'f');
    puts("Bye!");
    
    
    return 0;
}

void unbookingseat(void)
{
    unsigned int seatnumber;
    printf("Please inset the seat number that you want to unbook.\n");
    if (!(seatnumber = getchar())) {
        printf("The number you inster is out of ranl.\n");
        printf("Please inster again.\n");
        seatnumber = getchar();
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n') {
        continue;
    }
  
    emptytheplane(seatnumber);
    
}

void bookingseat(void)
{
    char input[LEN];
    unsigned int seatnumber;
    printf("Please inset the seat number that you want to book.\n");
   while (!(seatnumber = getchar())) {
        printf("The number you inster is out of ranl.\n");
        printf("Please inster again.\n");
        while (getchar() != '\n')
            continue;
    }
    while (seatnumber < 1 || seatnumber >12 || (plane[seatnumber-1].book))
    {
        printf("The number you inster is out of ranl.\n");
        printf("Please inster again.\n");
        scanf("%u", &seatnumber);
        while (getchar() != '\n')
            continue;
    }
    printf("Please inset your firstname:\n");
    s_gets(input, LEN);
    strcpy(plane[seatnumber - 1].firstname, input);

    printf("Please inset you lastname:\n");
    s_gets(input, LEN);
    strcpy(plane[seatnumber - 1].lastname, input);
    
    plane[seatnumber - 1].book = true;
    
}

void showinformationofunemptyseat(void)
{
    printf("There is the information of unempty seat.\n");
    printf("seatnumber,   bookable,    firstname,     lastname\n");
    for (int n = 0; n < TOTLE; n++)
    {
        if (plane[n].book == true) {
            printf("%2u, %d, %s, %s\n", plane[n].seatnumber, plane[n].book, plane[n].firstname, plane[n].lastname);
        }
    }
}


void showinformationofemptyseat(void)
{
    printf("There is the information of empty seat.\n");
    printf("seatnumber,   bookable,    firstname,     lastname\n");
    for (int n = 0; n < TOTLE; n++)
    {
        if (plane[n].book == false) {
            printf("%2u, %d, %s, %s\n", plane[n].seatnumber, plane[n].book, plane[n].firstname, plane[n].lastname);
        }
    }
}

void showemptyseat(void)
{
    printf("\n");
    printf("There is the empty seat number\n");
    for (int n = 0; n < TOTLE; n++)
    {
        if (plane[n].book == false)
        {
            printf("seat: %u\n", plane[n].seatnumber);
        }
        else
        {
            continue;
        }
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char i = 0;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
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
}


char showmanule(void)
{
    printf("\n");
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    char ans;
    putc('\n', stdout);
    puts("Now inter you option.");
    ans = getchar();
    while (getchar() != '\n') {
        continue;
    }
    
    return ans;
    
}

void showseats(void)
{
    printf("seatnumber,   bookable,    firstname,     lastname\n");
    for(int n = 0; n < TOTLE; n++)
    {
        printf("%2u, %d, %s, %s\n", plane[n].seatnumber, plane[n].book, plane[n].firstname, plane[n].lastname);
    }
    
}


void emptytheplane(int type)
{
    struct seats emptyseat = (struct seats){
        0, false, "unknow", "unknow"
    };
    if (type == 0)
    {
        for (int n = 0; n < TOTLE; n++)
        {
            plane[n] = emptyseat;
            plane[n].seatnumber = n + 1;
        }
    } else
    {
        plane[type - 1] = emptyseat;
        plane[type - 1].seatnumber = type;
    }
}
