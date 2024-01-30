# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
  
    def initialize(val = 0, _next = nil)
      @val = val
      @next = _next
    end
  end
  
  def add_two_numbers(l1, l2)
    dummy_head = ListNode.new
    current = dummy_head
    carry = 0
  
    while l1 || l2 || carry != 0
      val1 = l1 ? l1.val : 0
      val2 = l2 ? l2.val : 0
  
      total_sum = val1 + val2 + carry
      carry = total_sum / 10
      digit = total_sum % 10
  
      current.next = ListNode.new(digit)
      current = current.next
  
      l1 = l1 ? l1.next : nil
      l2 = l2 ? l2.next : nil
    end
  
    dummy_head.next
  end
