//
//  stack.c
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#include "stack.h"

Node * createNode(int data) {
    Node *node = malloc(sizeof(Node));

    if (node != NULL) {
        node->data = data;
    }
    
    return node;
}

Stack * createStack() {
    Stack *stack = malloc(sizeof(Stack));
    
    if (stack != NULL) {
        stack->top = NULL;        
    }

    return stack;
}

int push(Stack *stack, int data) {
    Node *tmp = NULL;
    Node *node = createNode(data);
    
    // Fail
    if (node == NULL) return 0;
    
    if (!isEmpty(stack)) {
        tmp = stack->top;
        node->next = tmp;
    }
    stack->top = node;
    
    return 1;
}

int pop(Stack *stack) {
    Node *tmp = NULL;
    
    // Nada para remover
    if (isEmpty(stack)) return 0;
    
    // "tmp" vai receber o topo
    tmp = stack->top;
    
    // O topo da pilha vai apontar para quem esta abaixo do topo dela
    stack->top = tmp->next;
    
    // Eliminamos o antigo topo da memória
    free(tmp);
    
    return 1;
}

int isEmpty(Stack *stack) {
    return (stack->top == NULL) ? 1 : 0;
}

void printStack(Stack *stack) {
    Node *tmp = stack->top;
    
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Stack *stack = createStack();
    
    if (stack == NULL) return 0;
    
    push(stack, 10);
    push(stack, 11);
    push(stack, 12);
    pop(stack);
    push(stack, 13);
    
    printStack(stack);
    
    return 1;
}