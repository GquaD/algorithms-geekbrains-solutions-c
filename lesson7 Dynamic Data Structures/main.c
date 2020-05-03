#include <stdio.h>
#include <stdlib.h>

#define T char
#define true 1==1
#define false 1!=1
typedef int boolean;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void init (Stack *stack) {
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack *stack, T value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack over flow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack) {
    if(stack->size == 0) {
        //printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    free(tmp);
    return data;
}

void printOneLinkCharNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkCharStack(Stack *stack) {
    Node *current = stack->head;
    if(current == NULL) {
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

//TASK #1.
//ZADANIE #1.
//RESHENIYE NA OSNOVE STACK'A

void firstTask() {
    char buf[100];
    printf("\nTask 1.\nInsert your string: ");
    scanf("%s", buf);
    printf("%s - inserted string", buf);

    Stack *opening = (Stack*) malloc(sizeof(Stack));
    init(opening);

    int count = 0;
    int countBraces = 0;
    while(buf[count] > 0) {
        if (buf[count] == '(' || buf[count] == '[' || buf[count] == '{') {
            push(opening, buf[count]);
            countBraces++;
        } else if (buf[count] == ')' || buf[count] == ']' || buf[count] == '}') {
            char open = pop(opening);
            char close = buf[count];
            countBraces++;
            if (!((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}'))) {
                printf("\nWRONG SEQUENCE! NE PRAVIL'NO!");
                return;
            }
        }
        count++;
    }
    if(opening->size > 0) {
        printf("\nWRONG SEQUENCE! NE PRAVIL'NO!");
        return;
    }
    if(countBraces == 0) {
        printf("\nNO BRACES! NET SKOBOK!");
        return;
    }
    printf("\nCORRECT SEQUENCE! PRAVIL'NO!");
    return;
}
//=====================================================
//TASK #2.
//ZADANIE #2.

typedef struct OneLinkNode {
    int datList;
    struct OneLinkNode *nextList;
} OneLinkNode;

typedef struct {
    OneLinkNode *headList;
    int sizeList;
} OneLinkList;

void initList (OneLinkList *list) {
    list->headList = NULL;
    list->sizeList = 0;
}

void insert(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->datList = data;
    new->nextList = NULL;

    OneLinkNode *current = lst->headList;
    if (current == NULL) {
        lst->headList = new;
        lst->sizeList++;
    } else {
        while (current->nextList != NULL) {
            current = current->nextList;
        }
        current->nextList = new;
        lst->sizeList++;
    }
}

OneLinkNode* rm(OneLinkList *lst, int data) {
    OneLinkNode *current = lst->headList;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->nextList != NULL && current->datList != data) {
        parent = current;
        current = current->nextList;
    }
    if (current->datList != data) {
        return NULL;
    }
    if (current == lst->headList) {
        lst->headList = current->nextList;
        lst->sizeList--;
        return current;
    }
    parent->nextList = current->nextList;
    lst->sizeList--;
    return current;
}

void printOneLinkNodeForList(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->datList);
}

void printOneLinkList(OneLinkList *lstOne) {
    OneLinkNode *current = lstOne->headList;
    if(current == NULL) {
        printOneLinkNodeForList(current);
    } else {
        do {
            printOneLinkNodeForList(current);
            current = current->nextList;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lstOne->sizeList);
}
//COPYING METHOD
//OSNOVNOY METOD DLYA KOPIROVANIYA
OneLinkList* copyOneLinkList(OneLinkList *lstL) {
    OneLinkList *resultList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initList(resultList);
    OneLinkNode *current = lstL->headList;
    do {
        insert(resultList, current->datList);
        current = current->nextList;
    }  while(current != NULL);
    return resultList;
}

void testCopyList() {
    printf("\n\nTask 2.\n");
    OneLinkList *myList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initList(myList);
    insert(myList, 1);
    insert(myList, 2);
    insert(myList, 3);
    insert(myList, 4);
    insert(myList, 5);
    //rm(myList, 3);
    printf("Original list: ");
    printOneLinkList(myList);
    printf("Copy of the list: ");
    printOneLinkList(copyOneLinkList(myList));
}

//=================================================================
//TASK #3.
//ZADANIE #3.
void isSorted(OneLinkList *lstS) {
    OneLinkNode *curr = lstS->headList;
    int temp = -1, asc = 0, desc = 0;
    temp = curr->datList;
    for (int i = 0; i < lstS->sizeList - 1; i++) {
        if (temp > curr->nextList->datList) {
            temp = curr->nextList->datList;
            desc++;
        } else if (temp < curr->nextList->datList) {
            temp = curr->nextList->datList;
            asc++;
        }
        curr = curr->nextList;
    }
    printOneLinkList(lstS);
    if (asc == lstS->sizeList - 1 || desc == lstS->sizeList - 1) {
        printf(" -> is SORTED!\n");
    } else {
        printf(" -> is NOT sorted!\n");
    }
}

void testSorted() {
    printf("\nTask 3.\nTest 1:\n");
    OneLinkList *myList1 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initList(myList1);
    insert(myList1, 0);
    insert(myList1, 1);
    insert(myList1, 2);
    insert(myList1, 3);
    insert(myList1, 4);
    isSorted(myList1);

    printf("\nTest 2:\n");
    OneLinkList *myList2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initList(myList2);
    insert(myList2, 10);
    insert(myList2, 9);
    insert(myList2, 8);
    insert(myList2, 6);
    insert(myList2, 5);
    isSorted(myList2);

    printf("\nTest 3:\n");
    OneLinkList *myList3 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initList(myList3);
    insert(myList3, 10);
    insert(myList3, 11);
    insert(myList3, 1);
    insert(myList3, 6);
    insert(myList3, 5);
    isSorted(myList3);
}

int main()
{
    //TASK 1
    //First task is to read a string and output true or false whether sequence of braces is correct or not
    firstTask();
    //TASK 2
    testCopyList();
    //TASK 3
    testSorted();

    return 0;
}
