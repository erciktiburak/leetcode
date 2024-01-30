// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        // Dummy head to simplify code and represent the head of the result linked list
        let mut dummy_head = ListNode::new(0);
        // Mutable references for l1, l2, current node in result list, and carry
        let (mut l1, mut l2, mut current, mut carry) =
            (l1, l2, &mut dummy_head, 0);

        // Traverse both linked lists until both are None and there is no carry
        while l1.is_some() || l2.is_some() || carry != 0 {
            // Extract values from the current nodes, default to 0 if None
            let (val1, val2) = (
                l1.as_ref().map_or(0, |node| node.val),
                l2.as_ref().map_or(0, |node| node.val),
            );

            // Calculate the sum and carry
            let total_sum = val1 + val2 + carry;
            carry = total_sum / 10;

            // Create a new node with the calculated digit and move the current pointer
            current.next = Some(Box::new(ListNode::new(total_sum % 10)));
            current = current.next.as_mut().unwrap();

            // Move to the next nodes if available, default to None if None
            if let Some(node) = l1 {
                l1 = node.next;
            }
            if let Some(node) = l2 {
                l2 = node.next;
            }
        }

        // Return the head of the resulting linked list
        dummy_head.next
    }
}
