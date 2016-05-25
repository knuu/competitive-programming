# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        dummy = ListNode(0)
        dummy.next = head
        prev, first, second = dummy, dummy.next, dummy.next.next
        while second:
            prev.next, first.next, second.next = second, second.next, first
            if not first.next:
                break
            prev, first, second = first, first.next, first.next.next
        return dummy.next
