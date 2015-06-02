//
//  list.c
//  ifpb_ads_esd
//
//  Created by Gustavo Vieira on 6/1/15.
//  Copyright (c) 2015 Gustavo Vieira. All rights reserved.
//

#include "list.h"

Node * createNode(int data) {
    Node *node = malloc(sizeof(Node));
    
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
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
    Node *aux = list;
    
    tmp = createNode(data);
    
    // Fail
    if (tmp == NULL) return 0;
    
    // Lista vazia
    if (aux == NULL) {
        list = tmp;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = tmp;
        tmp->prev = aux;
    }
    
    return 1;
}

int remNode(Node **list, int data) {
    Node *tmp = NULL;
    Node *aux = *list;
    
    // Lista vazia
    if (list == NULL) return 0;
    
    // "data" esta no primeiro elemento da lista
    if (aux->data == data) {
        aux->next->prev = NULL;
        *list = aux->next;
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
    
    // Remover qualquer elemento que não seja o último
    if (tmp->next != NULL)
        tmp->next->prev = aux;
    aux->next = tmp->next;
    free(tmp);
    
    return 1;
}

void printList(Node *list) {
    Node *tmp = list;
    
    while (tmp != NULL) {
        printf("%d(%d)%d ", (tmp->prev != NULL) ? tmp->prev->data : -1, tmp->data, (tmp->next != NULL) ? tmp->next->data : -1);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Node *list = createNode(4);
    printList(list);
    
    addNode(list, 5);
    printList(list);
    
    addNode(list, 6);
    printList(list);
    
    remNode(&list, 2);
    printList(list);
    
    return 1;
}