#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Adds two numbers represented as linked lists.
 *
 * @param l1 The head of the first linked list.
 * @param l2 The head of the second linked list.
 * @return The head of the resulting linked list representing the sum.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Dummy head to simplify code and represent the head of the result linked list
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    // Current pointer to traverse the result linked list
    struct ListNode* current = dummyHead;
    // Carry to handle addition overflow to the next place value
    int carry = 0;

    // Traverse both linked lists until both are null and there is no carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        // Extract values from the current nodes, default to 0 if null
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        // Calculate the sum and carry
        int totalSum = val1 + val2 + carry;
        carry = totalSum / 10; // Calculate carry for the next place value

        // Calculate the digit for the current place value
        int digit = totalSum % 10;

        // Create a new node with the calculated digit and move the current pointer
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = digit;
        current->next->next = NULL;
        current = current->next;

        // Move to the next nodes if available, default to null if null
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    // Return the head of the resulting linked list
    return dummyHead->next;
}
