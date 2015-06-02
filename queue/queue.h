//
//  queue.h
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#ifndef __ifpb_ads_esd__queue__
#define __ifpb_ads_esd__queue__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *first;
    Node *last;
} Queue;

Node * createNode(int data);
Queue * createQueue();
int enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int isEmpty(Queue *queue);
void printQueue(Queue *queue);

#endif /* defined(__ifpb_ads_esd__queue__) */
