#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initHashTable(int N) {
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT *) malloc(size * sizeof(listT));
    for (int i = 0; i < size; i++) {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char *element) {
    int z = hashFunction(element);
    hashTable[z] = addToList(hashTable[z], element);
}

int hashFunction(char *content) {
    int len = strlen(content);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += content[i];
    }
    int z=sum+content[0]*content[len-2];
    return z%size;
}

void computeDistributionsPerBucket(int N) {
    for (int i = 0; i < size; i++) {
        float x = (hashTable[i].size / N) * 100;
        printf("B%d: %f%c\n", i, x, '%');
    }
}
