/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        // Dummy head to simplify code and represent the head of the result linked list
        ListNode dummyHead = new ListNode();
        // Current pointer to traverse the result linked list
        ListNode current = dummyHead;
        // Carry to handle addition overflow to the next place value
        int carry = 0;

        // Traverse both linked lists until both are null and there is no carry
        while (l1 != null || l2 != null || carry != 0) {
            // Extract values from the current nodes, default to 0 if null
            int val1 = l1 != null ? l1.val : 0;
            int val2 = l2 != null ? l2.val : 0;

            // Calculate the sum and carry
            int totalSum = val1 + val2 + carry;
            carry = totalSum / 10; // Calculate carry for the next place value

            // Create a new node with the calculated digit and move the current pointer
            current.next = new ListNode(totalSum % 10);
            current = current.next;

            // Move to the next nodes if available, default to null if null
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