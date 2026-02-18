/* Problem: Given an array of integers, rotate the array to the right by k positions. */

#include <stdio.h>

void reverse(int a[], int l, int r) {
    while(l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);

    k = k % n;

    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
