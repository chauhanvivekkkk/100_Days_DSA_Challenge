/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards.
Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60),
while the other paints board of length 40.
*/

#include <stdio.h>

int canPaint(int* boards, int n, int k, int maxTime) {
    int painters = 1;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + boards[i] > maxTime) {
            painters++;
            curr = boards[i];
            if (painters > k) return 0;
        } else {
            curr += boards[i];
        }
    }
    return 1;
}

int minTime(int* boards, int n, int k) {
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > left) left = boards[i];
        right += boards[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));
    return 0;
}
