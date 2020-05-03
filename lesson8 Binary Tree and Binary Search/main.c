#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1==1
#define false 1!=1
typedef int boolean;

typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data) {
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;

    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode *root) {
    if(root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if(root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if(root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
//======================================================
//TASK #1.
//ZADANIE #2.
int countDepth = 0;
int tempCount = 0;

void depthCount(TreeNode * root) {
    if (root != NULL) {
        tempCount++;
        if (root->left != NULL) {
            depthCount(root->left);
        }
        if (root->right != NULL) {
            depthCount(root->right);
        }
    }
    if  (tempCount > countDepth) {
        countDepth = tempCount;
    }
    tempCount--;
}


int isBalanced(TreeNode *root, int num) {
    int countRight = 0, countLeft = 0;

    depthCount(root->left);
    countLeft = countDepth;
    countDepth = 0;
    tempCount = 1;

    depthCount(root->right);
    countRight = countDepth;
    countDepth = 0;
    tempCount = 1;

    if (countLeft == countRight || countLeft == countRight + 1 || countLeft == countRight - 1) {
        printf("%d - YES. Left: %d, right: %d\n", num + 1, countLeft, countRight);
        return 1;
    } else {
        printf("%d - NO. Left: %d, right: %d\n", num + 1, countLeft, countRight);
        return 0;
    }
}

void firstTaskTest() {
    int amountOfAllTrees = 50;
    int numOfNodes = 10000;
    int amountOfBalanced = 0;

    TreeNode *treeRoots[amountOfAllTrees];

    //init 50 trees with 10 000 random numbers
    for(int i = 0; i < amountOfAllTrees; i++) {
        int keyRand = rand() % numOfNodes;
        TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
        root->key = keyRand;
        root->left = NULL;
        root->right = NULL;
        treeRoots[i] = root;
        for(int j = 0; j < numOfNodes; j++) {
            int keyRandNode = rand() % numOfNodes;
            treeInsert(root, keyRandNode);
        }

        if (isBalanced(treeRoots[i], i) == 1) {
            amountOfBalanced++;
        }
    }
    float percentage = (amountOfBalanced  * 100.0 / amountOfAllTrees);

    printf("\nPercentage of balanced trees: %0.2f\n", percentage);
}

//======================================================================
//TASK #2.
//ZADANIE #2.

boolean binSearchRecursion(TreeNode *root, int value) {
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;

    if (value < root->key) {
        binSearchRecursion(root->left, value);
    } else if (value > root->key) {
        binSearchRecursion(root->right, value);
    }
}

void binSearchTest() {
    TreeNode *tree = (TreeNode*) malloc(sizeof(TreeNode));
    tree->key = (11);
    tree->left = NULL;
    tree->right = NULL;
    treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printf("Tree: ");
    printTree(tree);
    printf(" \n");

    printf("8 in tree = %s \n", binSearchRecursion(tree, 8) ? "true" : "false");
    printf("100 in tree = %s \n", binSearchRecursion(tree, 100) ? "true" : "false");
}

int main()
{
    printf("FIRST TASK.\n\n");
    firstTaskTest();
    printf("\nSECOND TASK.\nRecursive search.\n\n");
    binSearchTest();
    return 0;
}
