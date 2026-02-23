/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    if (n == 0) {
        printf("false");
        return 0;
    }

    struct ListNode *head = NULL, *tail = NULL, *cycleNode = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode *newnode = malloc(sizeof(struct ListNode));
        scanf("%d", &newnode->val);
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }

        if (i == 0)
            cycleNode = head;
    }

    scanf("%d", &pos);

    if (pos >= 0) {
        struct ListNode *temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        tail->next = temp;
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
