# Definition for singly-linked list.
#class ListNode(object):
#    def __init__(self, x):
#        self.val = x
#        self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        list_len = 0
        now = head
        while now:
            now = now.next
            list_len += 1
        prev, top = dummy, head
        while list_len >= k:
            for _ in xrange(k-1):
                top.next.next, prev.next, top.next = prev.next, top.next, top.next.next
            list_len -= k
            prev, top = top, top.next
        return dummy.next
