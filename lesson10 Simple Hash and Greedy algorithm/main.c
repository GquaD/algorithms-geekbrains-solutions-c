#include <stdio.h>
#include <stdlib.h>

//=================================================
//TASK #1
//ZADANIE #1

int simpleHashFunc(char* str) {
    int i = 0;
    int sum = 0;
    while (str[i] != 0) {
        printf("%d ", str[i]);
        sum += str[i++];
    }
    return sum;
}

void refreshBuf(char* str) {
    for(int i = 0; i < 100; i++) {
        str[i] = 0;
    }
}

void simpleHastTest() {
    char buf[100];
    refreshBuf(buf);
    printf("TASK #1.\nInsert your string: ");
    scanf("%s", buf);
    printf("\n%s - inserted string\n%d - sum of hashes", buf, simpleHashFunc(buf));
}

//===========================================================
//TASK #2
//ZADANIE #2

int greedyCoinsCount(int* coins) {
    int amount = 98;
    int count = 0;
    while(amount > 0) {
        if(amount / coins[0] > 0) amount = amount - coins[0];
        else if (amount / coins[1] > 0) amount = amount - coins[1];
        else if (amount / coins[2] > 0) amount = amount - coins[2];
        else if (amount / coins[3] > 0) amount = amount - coins[3];
        else amount = amount - coins[4];
        count++;
    }
    return count;
}

void testGreedy() {
    int coins[] = {50, 10, 5, 2, 1};
    printf("\nTASK #2\nI need %d coins for 98 cents.", greedyCoinsCount(coins));
    printf("\nNujno %d monet dlya 98 kopeek.", greedyCoinsCount(coins));
}

int main()
{
    simpleHastTest();
    testGreedy();
    return 0;
}
