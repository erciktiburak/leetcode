/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

// Define the ListNode class in the same file
class ListNode {
    val: number;
    next: ListNode | null;

    constructor(val: number = 0, next: ListNode | null = null) {
        this.val = val;
        this.next = next;
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const dummyHead: ListNode = new ListNode();
    let current: ListNode | null = dummyHead;
    let carry: number = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        // Extract digits from the current nodes
        const val1: number = l1 ? l1.val : 0;
        const val2: number = l2 ? l2.val : 0;

        // Calculate the sum and carry
        const totalSum: number = val1 + val2 + carry;
        carry = Math.floor(totalSum / 10);
        const digit: number = totalSum % 10;

        // Create a new node with the calculated digit and move the current pointer
        current.next = new ListNode(digit);
        current = current.next;

        // Move to the next nodes if available
        if (l1 !== null) {
            l1 = l1.next;
        }
        if (l2 !== null) {
            l2 = l2.next;
        }
    }

    return dummyHead.next;
}