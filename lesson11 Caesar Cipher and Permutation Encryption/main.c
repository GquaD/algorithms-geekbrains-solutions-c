#include <stdio.h>
#include <stdlib.h>


//==================================================
//TASK #1
//ZADANIE #1

void refreshBuf(char* str) {
    for(int i = 0; i < 100; i++) {
        str[i] = 0;
    }
}

char* encryptCaesar(char* string, int step) {
    int i = 0;
    //encrypting by taking into account ASCII numbers for chars
    //shifruyu s uchetom ASCII nomerov simvolov
    while(string[i] > 0) {
        char temp = string[i] + (char)step;
        if (temp > 122) {
            string[i] = 96 + (temp % 122);
            i++;
        } else if (string[i] <= 90 && temp > 90) {
            string[i] = 64 + (temp % 90);
            i++;
        } else {
//            printf("%c, ", )
            string[i] = temp;
            i++;
        }
    }
    return string;
}

char* decryptCaesar(char* string, int step) {
    int i = 0;
    while(string[i] > 0) {
        char temp = string[i] - (char)step;
        if (temp < 65) {
            string[i] = 90 - (step - string[i] % 65 - 1);
            i++;
        } else if (string[i] >= 97 && string[i] <= 122 && temp < 97) {
            string[i] = 122 - (step - string[i] % 97 - 1);
            i++;
        } else {
          string[i] = temp;
          i++;
        }
    }
    return string;
}

void testCaesar() {
    char buf[100];
    int step = 4;
    refreshBuf(buf);
    printf("TASK #1.\nInsert your string: ");
    scanf("%s", buf);
    printf("\n%s - inserted string", buf);
    printf("\n%s - Caesar encryption", encryptCaesar(buf, step));
    printf("\n%s - Caesar decryption", decryptCaesar(buf, step));
}

void testCaesarNoInput() {
    char buf[100] = "abcdefghijklmnopqrstuvwxyz";
    int step = 4;
    printf("TASK #1.\n");
    printf("\n%s - given string", buf);
    printf("\n%s - Caesar encryption", encryptCaesar(buf, step));
    printf("\n%s - Caesar decryption", decryptCaesar(buf, step));
}

//==================================================
//TASK #2
//ZADANIE #2
char result[100];
char forDecrypt[100];

char* encryptPermutation(char* str, int key, int size) {
    refreshBuf(result);
    int columns = (size % key == 0) ? size / key : size / key + 1;
    int i = 0;
    while(str[i] > 0) {
        int posY = i / key;
        int posX = i % key;
        int index = posX * columns + posY;
        result[index] = str[i++];
    }
    printf("\n%s - permutation encryption", result);
    return result;
}

char* decryptPermutation(char* str, int key, int size) {
    char res[100];
    refreshBuf(res);
    int i = 0;
    int columns = (size % key == 0) ? size / key : size / key + 1;
    while(str[i] > 0) {
        int posY = i / columns;
        int posX = i % columns;
        int index = posX * key + posY;
        res[index] = result[i++];
    }
    printf("\n%s - permutation decryption", res);
    return res;
}

int stringSize(char* str) {
    int size = 0;
    while(str[size] > 0) {
        size++;
    }
    return size;
}

void testPermutation() {
    char input[100];
    refreshBuf(input);
    int key = 4;
    printf("\n\nTASK #2.\nInsert your string: ");
    scanf("%s", input);
    int size = stringSize(input);
    printf("\n%s - inserted string", input);
    encryptPermutation(input, key, size);
    decryptPermutation(result, key, size);
}

void testPermutationNoInput() {
    char input[100] = "abcdefghijklmnopqrst";
    int key = 4;
    int size = stringSize(input);
    printf("\n\nTASK #2.\n");
    printf("\n%s - given string", input);
    encryptPermutation(input, key, size);
    decryptPermutation(result, key, size);
}

void testWithConsole() {
    testCaesar();
    testPermutation();
}

void testNoConsoleInput() {
    testCaesarNoInput();
    testPermutationNoInput();
}

int main()
{
    testNoConsoleInput();
    printf("\n\nTEST WITH USER INPUT.\nPLEASE, TAKE INTO ACCOUNT <KEY> VARIABLE IN TASK #2. \n!!!YOUR INPUT'S CHARS NUMBER MUST BE DIVISIBLE BY KEY WITH NO REMAINDER!!!\n\n");
    testWithConsole();
    //abcdefghijklmnopqrst
    return 0;
}
