# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        sum_val = (l1.val if l1 else 0) + (l2.val if l2.val else 0)
        ret = ListNode(sum_val % 10)
        if l1.next:
            l1.next.val += sum_val // 10
            ret.next = self.addTwoNumbers(l1.next, l2.next if l2.next else ListNode(0))
        elif l2.next:
            l1_next = ListNode(sum_val // 10)
            ret.next = self.addTwoNumbers(l1_next, l2.next)
        elif sum_val // 10 > 0:
            ret.next = ListNode(sum_val // 10)
        return ret
