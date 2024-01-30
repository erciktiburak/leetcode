/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    // Dummy head to simplify code and represent the head of the result linked list
    dummyHead := &ListNode{}
    // Current pointer to traverse the result linked list
    current := dummyHead
    // Carry to handle addition overflow to the next place value
    carry := 0

    // Traverse both linked lists until both are null and there is no carry
    for l1 != nil || l2 != nil || carry != 0 {
        // Extract values from the current nodes, default to 0 if null
        val1, val2 := 0, 0
        if l1 != nil {
            val1 = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            val2 = l2.Val
            l2 = l2.Next
        }

        // Calculate the sum and carry
        totalSum := val1 + val2 + carry
        carry = totalSum / 10 // Calculate carry for the next place value

        // Calculate the digit for the current place value
        digit := totalSum % 10

        // Create a new node with the calculated digit and move the current pointer
        current.Next = &ListNode{Val: digit}
        current = current.Next
    }

    // Return the head of the resulting linked list
    return dummyHead.Next
}