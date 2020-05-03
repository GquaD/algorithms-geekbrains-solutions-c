#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

#define SZ 10
//====================================
//TASK #1
//ZADANIE #1
typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        //just inserting to the end of array
		arr[tail % SZ] = node;
        items++;
        tail++;
    }
}

Node* rem() {
    if (items == 0) {
        return NULL;
    } else {
        Node *temp;
        int index = 0;
        int max = arr[0]->pr;
        //searching node with largest priority
        for(int i = 1; i < items; i++) {
            if(max < arr[i]->pr) {
                max = arr[i]->pr;
                index = i;
            }
        }
        //storing node to return
        temp = arr[index];

        //moving nodes to left
        for(int j = index; j < items; j++) {
            arr[j] = arr[j + 1];
        }

        tail--;
        items--;
        return temp;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

void prQueueTest() {
    initQueue();
    ins(8, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(7, 100);
    printQueue();
    for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
        printQueue();
    }
    //printQueue();

    ins(1, 110);
    ins(6, 120);
    ins(3, 130);
    printQueue();

    rem();
    printQueue();

}

//=========================================
typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

//TASK #2.
//ZADANIE #2.
void toBinary(int num) {
    if  (num == 0) printf("0");
    int count = 0;
    while(num > 0) {
        int temp = num % 2;
        pushStack(temp);
        num /= 2;
        count++;
    }
    for (int i = 0; i < count; i++) {
        printf("%d", popStack());
    }
}



int main()
{
    int number = 11;
    printf("Task 1.\n");
    prQueueTest();
    printf("\nTask 2.\nNumber %d in binary system: ", number);
    toBinary(number);
    return 0;
}
