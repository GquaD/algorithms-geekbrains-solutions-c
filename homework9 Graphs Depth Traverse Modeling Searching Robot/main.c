#include <stdio.h>
#include <stdlib.h>


#define T char
#define true 1==1
#define false 1!=1
typedef int boolean;

typedef struct Node {
    int dat;
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

boolean push(Stack *stack, int value) {
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

int pop(Stack *stack) {
    if(stack->size == 0) {
        //printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    int data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    free(tmp);
    return data;
}

int peak(Stack *stack) {
    if(stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    return stack->head->dat;
}

void printOneLinkCharNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
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
//====================================================
#define n 6
int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visitedDepth[n] = {0};

void depthTravers(int st) {
    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            depthTravers(r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visitedDepth[i] = 0;
    }
}

void depthTest() {
    printf("Realizatsiya prepodavatelya cherez massiv. \nTutor's realization based on array: \n");
    depthTravers(0);
    resetArr();
    printf("\n");
    depthTravers(2);
    resetArr();
    printf("\n");
    depthTravers(1);
    resetArr();
    printf("\n");
}

//============================================
//TASK #1.
//ZADANIE #1.
//checks whether stack contains num
boolean stackContains(Stack *stack, int num) {
    Node *tmp = stack->head;
    while(tmp != NULL) {
        if (tmp->dat == num) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void depthTraverseStack(Stack *stack, int st) {
    printf("%d ", st);
    push(stack, st);
    for (int r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !stackContains(stack, r)) {
            depthTraverseStack(stack, r);
        }
    }
}

void testTraverseStack() {
    printf("\nMoya realizatsiya na osnove steka.\nMy realization based on stack: \n");
    Stack *recur = (Stack*) malloc(sizeof(Stack));
    init(recur);
    printf("Depth tr: ");
    depthTraverseStack(recur, 0);
    printf("\nStack: ");
    printOneLinkCharStack(recur);

    Stack *recur1 = (Stack*) malloc(sizeof(Stack));
    init(recur1);
    printf("Depth tr: ");
    depthTraverseStack(recur1, 2);
    printf("\nStack: ");
    printOneLinkCharStack(recur1);

    Stack *recur2 = (Stack*) malloc(sizeof(Stack));
    init(recur2);
    printf("Depth tr: ");
    depthTraverseStack(recur2, 1);
    printf("\nStack: ");
    printOneLinkCharStack(recur2);
}

//======================================
//TASK #2. PART 1.
//ZADANIE #2. CHAST' 1.
#define nodesNum 14
int matr[nodesNum][nodesNum] = {
 //      A  B  C  D  E  F  G  H  I  J  K  L  M  N
 /*A*/  {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
 /*B*/  {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
 /*C*/  {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 /*D*/  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
 /*E*/  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
 /*F*/  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 /*G*/  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
 /*H*/  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
 /*I*/  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 /*J*/  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 /*K*/  {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
 /*L*/  {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
 /*M*/  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
 /*N*/  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

int visitedDepthAdj[nodesNum] = {0};
int numOfAdjacent[nodesNum] = {0};
char letters[nodesNum] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N'};

//METHOD FROM TUTORIAL
//METOD IZ UROKA

void resetArrAdj() {
    for (int i = 0; i < nodesNum; ++i) {
        visitedDepthAdj[i] = 0;
        numOfAdjacent[i] = 0;
    }
}

void printArray1D(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d", arr[i]);
    }
}

//twoLinkList queue
//building first part of the second task based on twolinked queue
typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = NULL;
}

boolean enqueue(TwoLinkList *queue, int value) {
    TwoLinkNode *temp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (temp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    temp->dat = value;
    temp->next = NULL;
    temp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = temp;
    }
    if (queue->head == NULL) {
        queue->head = temp;
    }

    queue->tail = temp;
    queue->size++;
    return true;
}

int dequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *temp = queue->head;
    int data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (temp == queue->tail) {
        queue->tail = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

void printTwoLinkNode(TwoLinkNode *node) {
    if (node == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", node->dat);
}

void printTwoLinkList(TwoLinkList *list) {
    TwoLinkNode *current = list->head;
    if  (current == NULL) {
        printTwoLinkNode(current);
    } else {
        do {
            printTwoLinkNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", list->size);
}

void queueTest() {
    TwoLinkList *q = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    dequeue(q);
    printf("\nPrinting Queue:\n");
    printTwoLinkList(q);
}

void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void widthTraversAdjCount(int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    enqueue(queue, start);
    while (queue->size > 0) {
        int indx = dequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d ", indx);
        for (int i = 0; i < size; ++i) {
            if (matr[indx][i] == 1) {
                numOfAdjacent[i]++;
                enqueue(queue, i);
            }
        }
    }
}

//CODE FOR SORTING RESULTS OF CONNECTIONS
//====================================================


typedef struct OneLinkNode {
    T datList;
    int num;
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

void insert(OneLinkList *lst, int data, char c) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->datList = data;
    new->num = c;
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

void printOneLinkNodeForList(OneLinkNode *node) {
    if (node == NULL) {
        printf("[]");
        return;
    }
    printf("[%c-%d]", node->datList, node->num);
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

void createListWithNodesAndConnections(OneLinkList *list, char *lett, int *connections, int size) {
    for(int i = 0; i < size; i++) {
        insert(list, lett[i], connections[i]);
    }
}

void sortResultList(OneLinkList *lst, int size) {
    for(int i = 0; i < size; i++) {
    OneLinkNode *firstNode = lst->headList;
    int first = firstNode->num;
    for(int j = 0; j < size; j++) {
        OneLinkNode *nextNode = firstNode->nextList;
        if(nextNode != NULL){
            if(firstNode->num < nextNode->num) {
                int tempInt = nextNode->num;
                char tempChar = nextNode->datList;
                nextNode->datList = firstNode->datList;
                nextNode->num = firstNode->num;
                firstNode->datList = tempChar;
                firstNode->num = tempInt;
                firstNode = nextNode;
            } else {
                firstNode = nextNode;
            }
        }
    }
}
}

//====================================================
//TASK #2, PART 2.
//ZADANIE #2, CHAST' 2.
int taskTwoArrayForConnections[nodesNum] = {0};
void countConnectionsBy2DArray(int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matr[i][j] == 1) {
                taskTwoArrayForConnections[i]++;
            }
        }
    }
}

void sortArray1D(int size) {
    //int check = taskTwoArrayForConnections[0];
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(taskTwoArrayForConnections[i] > taskTwoArrayForConnections[j]) {
                int temp = taskTwoArrayForConnections[i];
                taskTwoArrayForConnections[i] = taskTwoArrayForConnections[j];
                taskTwoArrayForConnections[j] = temp;
            }
        }
    }
}

void testWidthTraverseWithAdjCount() {
    resetArrAdj();
    printf("\nTASK 2. PART 1.\nZADANIE 2. CHAST' 1.\n");
    printf("\nCalculating number of adjacent nodes WIDTH RECURSIVE algorithm: \n");
    widthTraversAdjCount(0, nodesNum); //0 -> A
    printf(" |");
    printArray1D(numOfAdjacent, nodesNum);

    //MOJESH POTESTIT' ZDES'
    //RASKOMMENTIRUY I UKAJI LYUBOY UZEL VMESTO 2
    //YOU CAN TEST HERE
    //UNCOMMENT AND CHANGE NUMBER 2 TO ANY OTHER VALUE FROM THE GRAPH
//    resetArrAdj();
//    printf("\nCalculating number of adjacent nodes WIDTH RECURSIVE algorithm: \n");
//    widthTraversAdjCount(matr, 2, nodesNum);
//    printf(" |");
//    printArray1D(numOfAdjacent, nodesNum);

    //putting elements to list with char value and number of connections
    OneLinkList *list = (OneLinkList*) malloc(sizeof(OneLinkList));
    list->headList = NULL;
    list->sizeList = 0;
    createListWithNodesAndConnections(list, letters, numOfAdjacent, nodesNum);
    printf("\nSORTING.\nNot sorted list: ");
    printOneLinkList(list);
    sortResultList(list, nodesNum);
    printf("\nSorted list:     ");
    printOneLinkList(list);

    printf("\nTASK 2. PART 2.\nZADANIE 2. CHAST' 2.\n");
    printf("\nCalculated number of adjacent nodes via 2D ARRAY algorithm:");
    countConnectionsBy2DArray(nodesNum);
    printArray1D(taskTwoArrayForConnections, nodesNum);
    printf("\nSORTING.\nNot sorted array: ");
    printArray1D(taskTwoArrayForConnections, nodesNum);

    sortArray1D(nodesNum);
    printf("\nSORTING.\nSorted array: ");
    printArray1D(taskTwoArrayForConnections, nodesNum);
}


int main()
{
    depthTest();
    testTraverseStack();
    printf("\n");
    testWidthTraverseWithAdjCount();
    return 0;
}
