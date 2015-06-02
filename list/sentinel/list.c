//
//  list.c
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#include "list.h"

Node * createList() {
    Node *node = malloc(sizeof(Node));
    
    if (node != NULL) {
        node->data = 0;
        node->next = NULL;
    }
    
    return node;
}

Node * createNode(int data) {
    Node *node = malloc(sizeof(Node));
    
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    
    return node;
}

/* addNode
 * - node
 * - data
 *
 * Adiciona um novo nó ao final da lista
 */
int addNode(Node *list, int data) {
    Node *tmp = NULL;
    Node *aux = list->next;
    
    tmp = createNode(data);
    
    // Fail
    if (tmp == NULL) return 0;
    
    // Lista vazia
    if (aux == NULL) {
        list->next = tmp;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = tmp;
    }
    
    return 1;
}

int remNode(Node *list, int data) {
    Node *tmp = NULL;
    Node *aux = list->next;
    
    // Lista vazia
    if ((list == NULL) || (aux == NULL)) return 0;
    
    // "data" esta no primeiro elemento da lista
    if (aux->data == data) {
        list->next = aux->next;
        free(aux);
        aux = NULL;
        
        return 1;
    }
    
    // aux->next == NULL => Fim da lista
    while (aux->next != NULL && aux->next->data != data) {
        aux = aux->next;
    }
    
    if (aux->next == NULL) return 0;
    
    tmp = aux->next;
    aux->next = tmp->next;
    free(tmp);
    
    return 1;
}

void printList(Node *list) {
    Node *tmp = list->next;
    
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Node *list = createList();
    printList(list);
    
    addNode(list, 4);
    printList(list);
    
    addNode(list, 5);
    printList(list);
    
    addNode(list, 6);
    printList(list);
    
    remNode(list, 2);
    printList(list);
    
    return 1;
}