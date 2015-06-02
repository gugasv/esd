# Estrutura de Dados - Pilha

![Pilha][stack]

```c
typedef struct node {
    int data;
    struct node *next;
} Node;
```

```c
typedef struct stack {
    Node *top;
} Stack;
```
```c
Node * createNode(int data);
```

```c
Stack * createStack();
```

```c
int push(Stack *stack, int data);
```

```c
int pop(Stack *stack);
```

```c
int isEmpty(Stack *stack);
```

```c
void printStack(Stack *stack);
```

[stack]: http://upload.wikimedia.org/wikipedia/commons/thumb/2/29/Data_stack.svg/391px-Data_stack.svg.png "Fonte: http://upload.wikimedia.org/wikipedia/commons/thumb/2/29/Data_stack.svg/391px-Data_stack.svg.png"