#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 3
#define COL 5


//helper methods from tutorial
//=====================================
void swapInt(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

char** initArray(char** array, const int row, const int col) {
    array = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (char*) calloc(sizeof(char), col);
    }
    return array;
}

void fillArray(char** array, const int row, const int col) {
    int max = col * row;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = rand() % max + 1;
        }
    }
}

void printArray(char** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%4d", *((*(array + i)) + j));
        }
        printf("\n");
    }
}
//=====================================

//1 TASK
void bubbleSort2D(char** arr, int y, int x) {
	int len = x*y, count = 0;
	int array[len];
	//putting all elements of 2d array into 1d array
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			array[count] = *((*(arr + i)) + j);
			count++;
		}
	}
	//sorting
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (array[j] > array[j + 1])
                swapInt(&array[j], &array[j + 1]);
        }
    }

    //putting all elements of 1d array back to 2d array
    count = 0;
    for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			*((*(arr + i)) + j) = array[count];
			count++;
		}
	}
}

//2nd TASK: TPK algorithm
void methodTPK() {
    int length = 11;
    int arrayTPK[length];
    //reading 11 numbers
    for (int i = 0; i < length; i++) {
        printf("Vvedite chislo #%d: ", i+1);
        scanf("%d", &arrayTPK[i]);
    }
    //reversing
    for (int i = 0; i < length/2; i++) {
            swapInt(&arrayTPK[i], &arrayTPK[length - i - 1]);
    }
    //calculations and writing to console
    int count = 0;
    for (int i = 0; i < length; i++) {
        if(sqrt(fabs(arrayTPK[i])) + 5 * pow(arrayTPK[i], 3) > 400) {
            printf("Dlya chisla %d vichisleniya po formule previshayut 400.\n", arrayTPK[i]);
            count++;
        }
    }
    if (count == 0) printf("-1");
}

int main()
{
    char** newArr = initArray(newArr, ROW, COL);
    fillArray(newArr, ROW, COL);
    printArray(newArr, ROW, COL);
    printf("\n");
    bubbleSort2D(newArr, ROW, COL);
    printArray(newArr, ROW, COL);

    printf("\n");
    methodTPK();
    return 0;
}

