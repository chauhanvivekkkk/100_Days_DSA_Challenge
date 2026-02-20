
/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int absVal(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int minSum = arr[l] + arr[r];
    int x = arr[l], y = arr[r];

    while(l < r) {
        int sum = arr[l] + arr[r];

        if(absVal(sum) < absVal(minSum)) {
            minSum = sum;
            x = arr[l];
            y = arr[r];
        }

        if(sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);
    return 0;
}
