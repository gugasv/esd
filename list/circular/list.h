//
//  list.h
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#ifndef __ifpb_ads_esd__list__
#define __ifpb_ads_esd__list__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node * createNode(int data);
int addNode(Node *list, int data);
int remNode(Node **list, int data);
void printList(Node *list);

#endif /* defined(__ifpb_ads_esd__list__) */
