# Estrutura de Dados - Fila

![Fila][queue]

```c
typedef struct node {
    int data;
    struct node *next;
} Node;
```

```c
typedef struct queue {
    Node *first;
    Node *last;
} Queue;
```

```c
Node * createNode(int data);
```

```c
Queue * createQueue();
```

```c
int enqueue(Queue *queue, int data);
```

```c
int dequeue(Queue *queue);
```

```c
int isEmpty(Queue *queue);
```

```c
void printQueue(Queue *queue);
```

[queue]: http://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/405px-Data_Queue.svg.png "Fonte: http://en.wikipedia.org/wiki/Queue_(abstract_data_type)#/media/File:Data_Queue.svg"