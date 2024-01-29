/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /**
     * Adds two numbers represented as linked lists.
     *
     * @param l1 The head of the first linked list.
     * @param l2 The head of the second linked list.
     * @return The head of the resulting linked list representing the sum.
     */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Create a dummy head for the resulting linked list
        ListNode dummyHead = new ListNode();
        // Initialize a current pointer to the dummy head
        ListNode current = dummyHead;
        // Initialize the carry to 0
        int carry = 0;

        // Iterate through the linked lists until both are null and there is no carry
        while (l1 != null || l2 != null || carry != 0) {
            // Extract digits from the current nodes
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;

            // Calculate the sum and carry
            int totalSum = val1 + val2 + carry;
            carry = totalSum / 10;
            int digit = totalSum % 10;

            // Create a new node with the calculated digit and move the current pointer
            current.next = new ListNode(digit);
            current = current.next;

            // Move to the next nodes if available
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }

        // Return the head of the resulting linked list
        return dummyHead.next;
    }
}