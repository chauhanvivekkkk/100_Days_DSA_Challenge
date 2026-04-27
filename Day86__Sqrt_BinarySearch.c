/* 
Problem: Find the integer square root of a given non-negative integer using Binary Search.
The integer square root of a number is defined as the greatest integer whose square 
is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input: 64   Output: 8
Input: 20   Output: 4
Input: 1    Output: 1
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n == 0 || n == 1) {
        printf("Integer square root: %d", n);
        return 0;
    }

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            printf("Integer square root: %lld", mid);
            return 0;
        } else if (mid * mid < n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Integer square root: %d", ans);
    return 0;
}
