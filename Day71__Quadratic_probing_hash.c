/* 
Problem Statement:
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m

Input Format:
Same as previous.

Output Format:
Result of SEARCH operations.

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND

Explanation:
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[1000];
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);
    int i = 0;
    int idx;
    while (i < m) {
        idx = (h + i * i) % m;
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int search(int key) {
    int h = hash(key);
    int i = 0;
    int idx;
    while (i < m) {
        idx = (h + i * i) % m;
        if (table[idx] == EMPTY) return 0;
        if (table[idx] == key) return 1;
        i++;
    }
    return 0;
}

int main() {
    int q, key;
    char op[10];

    printf("Enter table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    for (int i = 0; i < m; i++) table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        printf("Enter operation and key: ");
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
