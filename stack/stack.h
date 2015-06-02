//
//  stack.h
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#ifndef __ifpb_ads_esd__stack__
#define __ifpb_ads_esd__stack__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Node * createNode(int data);
Stack * createStack();
int push(Stack *stack, int data);
int pop(Stack *stack);
int isEmpty(Stack *stack);
void printStack(Stack *stack);

#endif /* defined(__ifpb_ads_esd__stack__) */
