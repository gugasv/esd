# Estrutura de Dados - Lista com cabeça

Obs: Apesar de na lista nós podermos adicionar e remover um elemento em qualquer posição, nestes códigos foi apenas impelementado a inserção na última posição.

```c
typedef struct node {
    int data;
    struct node *next;
} Node;
```

```c
Node * createList();
```

```c
Node * createNode(int data);
```

```c
int addNode(Node *list, int data);
```

```c
int remNode(Node *list, int data);
```

```c
void printList(Node *list);
```