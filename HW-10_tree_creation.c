#include <stdio.h>

#define SIZE 15   // maksimum node sayýsý

int tree[SIZE];

// Aðacý baþlat
void initTree() {
     int i;
     for (i = 0; i < SIZE; i++) {
        tree[i] = -1; // -1 = boþ node
    }
}

// Node ekleme
void insert(int index, int value) {
     if (index >= SIZE) {
        printf("Index sýnýrý aþýldý!\n");
        return;
    }
    tree[index] = value;
}

// Tree yazdýrma
void printTree() {
     int i;
     for (i = 0; i < SIZE; i++) {
        if (tree[i] != -1)
            printf("Index %d : %d\n", i, tree[i]);
    }
}

int main() {
    initTree();

    insert(0, 10);          // root
    insert(1, 5);           // left child
    insert(2, 20);          // right child
    insert(3, 3);
    insert(4, 7);
    insert(5, 15);

    printTree();

    return 0;
}
