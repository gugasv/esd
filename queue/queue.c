//
//  queue.c
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#include "queue.h"

Node * createNode(int data) {
    Node *node = malloc(sizeof(Node));
    
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    
    return node;
}

Queue * createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    
    if (queue != NULL) {
        queue->first = NULL;
        queue->last = NULL;
    }
    
    return queue;
}

int enqueue(Queue *queue, int data) {
    Node *node = createNode(data);
    
    // Fail
    if (node == NULL) return 0;
    
    if (isEmpty(queue)) {
        queue->first = node;
    } else {
        queue->last->next = node;
    }
    queue->last = node;
    
    return 1;
}

int dequeue(Queue *queue) {
    Node *tmp;
    
    // Nada para remover
    if (isEmpty(queue)) return 0;

    tmp = queue->first;
    queue->first = tmp->next;
    
    free(tmp);
    
    if (queue->first == NULL) {
        queue->last = NULL;
    }
    
    return 1;
}

int isEmpty(Queue *queue) {
    return (queue->first == NULL) ? 1 : 0;
}

void printQueue(Queue *queue) {
    Node *tmp = queue->first;
    
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();
    
    if (queue == NULL) return 0;
    
    enqueue(queue, 10);
    printQueue(queue);
    
    enqueue(queue, 11);
    printQueue(queue);
    
    enqueue(queue, 12);
    printQueue(queue);
    
    enqueue(queue, 13);
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    dequeue(queue);
    printQueue(queue);
    
    return 1;
}

