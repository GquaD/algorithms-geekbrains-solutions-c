#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}

void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void swapInt(int *a, int *b) {

    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void sortInserts(int* arr, int len) {
    int temp, pos;
    for (int i = 1; i < len; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

//TASK #1
//ZADANIE #1
void advancedQuickSort(int* arr, int first, int last) {
    if(last - first <= 10 && last - first > 0) {
        int sizeTemp = fabs(last - first);
        sortInserts(arr, sizeTemp);
    } else {
        int begin = arr[first], end = arr[last], mid = arr[(first+last) / 2];
        if ((begin > end && end > mid) || (mid > end && end > begin)) {
            swapInt(&arr[last], &arr[(first+last) / 2]);
        } else if ((end > begin && begin > mid) || (mid > begin && begin > end)) {
            swapInt(&arr[first], &arr[(first+last) / 2]);
        }
    }
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) advancedQuickSort(arr, i, last);
    if (first < j) advancedQuickSort(arr, first, j);
}

//TASK 2
//ZADANIE #2
void bucketSort(int* arr, int len) {
    const int max = len;
    const int b = 10;

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10) {
        for (int i = 0; i < max; ++i) {
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                if(arr[idx] % 2 == 0 && buckets[i][j] % 2 == 0) {
                    arr[idx++] = buckets[i][j];
                } else if (arr[idx] % 2 != 0 && buckets[i][j] % 2 != 0) {
                    idx++;
                } else if (arr[idx] % 2 != 0 && buckets[i][j] % 2 == 0) {
                    idx++;
                    j--;
                }
            }
            buckets[i][max] = 0;
        }

    }
}

void bucketTest() {
    const int SZ = 40;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    bucketSort(arr, SZ);
    printIntArray(arr, SZ, 3);
}

void qSortTest() {
    const int SZ = 100;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    advancedQuickSort(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
}

int main( int argc, const char* argv[] ) {
	qSortTest();
	printf("\n");
	bucketTest();
}
