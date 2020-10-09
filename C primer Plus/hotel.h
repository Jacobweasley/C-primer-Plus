//
//  hotel.h
//  C primer Plus
//
//  Created by 大娘 on 2020/10/9.
//

#ifndef hotel_h
#define hotel_h

#include <stdio.h>
#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "*********************************"

int menu(void);

int getnights(void);

void showprice(double rate, int nights);


#endif /* hotel_h */
