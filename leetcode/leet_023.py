# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        import heapq
        dummy = ListNode(0)
        now = dummy
        pque = [(l.value, i) for i, l in enumerate(lists) if l]
        heapq.heapify(pque)
        while pque:
            v, i = heapq.heappop(pque)
            now.next = lists[i]
            lists[i] = lists[i].next
            now = now.next
            if lists[i]:
                heapq.heappush(pque, (lists[i].value, i))
        return dummy.next
