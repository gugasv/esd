# Estrutura de Dados - Lista duplamente encadeada

![Lista sem cabeça][list]

Obs: Apesar de na lista nós podermos adicionar e remover um elemento em qualquer posição, nestes códigos foi apenas impelementado a inserção na última posição.

```c
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;
```

```c
Node * createNode(int data);
```

```c
int addNode(Node *list, int data);
```

```c
int remNode(Node **list, int data);
```

```c
void printList(Node *list);
```

[list]: http://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Doubly-linked-list.svg/610px-Doubly-linked-list.svg.png "Fonte: http://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Doubly-linked-list.svg/610px-Doubly-linked-list.svg.png"