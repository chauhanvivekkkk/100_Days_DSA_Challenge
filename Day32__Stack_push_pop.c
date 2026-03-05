// Problem: Implement push and pop operations on a stack and verify stack operations.
// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)
// Output:
// - Print remaining stack elements from top to bottom

#include <stdio.h>

int main()
{
    int stack[100], top = -1;
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        stack[++top] = x;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }

    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
