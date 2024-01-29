/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.next = (next === undefined ? null : next);
 * }
 */

/**
 * Adds two numbers represented as linked lists.
 *
 * @param {ListNode} l1 The head of the first linked list.
 * @param {ListNode} l2 The head of the second linked list.
 * @return {ListNode} The head of the resulting linked list representing the sum.
 */

var addTwoNumbers = function (l1, l2) {
    // Dummy head to simplify code and represent the head of the result linked list
    const dummyHead = new ListNode();
    // Current pointer to traverse the result linked list
    let current = dummyHead;
    // Carry to handle addition overflow to the next place value
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        // Extract values from the current nodes, default to 0 if null
        const val1 = l1 ? l1.val : 0;
        const val2 = l2 ? l2.val : 0;

        // Calculate the sum and carry
        const totalSum = val1 + val2 + carry;
        carry = totalSum >= 10 ? 1 : 0; // Calculate carry for the next place value

        // Calculate the digit for the current place value
        const digit = totalSum % 10;

        // Create a new node with the calculated digit and move the current pointer
        current.next = new ListNode(digit);
        current = current.next;

        // Move to the next nodes if available, default to null if null
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }

    // Return the head of the resulting linked list
    return dummyHead.next;
};
