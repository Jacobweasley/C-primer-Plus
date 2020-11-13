//
//  list.h
//  C primer Plus
//
//  Created by 大娘 on 2020/11/12.
//

#ifndef list_h
#define list_h
#include <stdbool.h>
#include <stdio.h>
#define TSIZE 45

struct film
{
    char titleIntializeListnt rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef Node * List;

void IntializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List * plist);

void Traverse(const List *plist, void(*pfun)(Item item));

void EmptyTheList(List * plist);


#endif /* list_h */
