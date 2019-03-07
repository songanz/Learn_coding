# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# when swap pairs, we need to modify three nodes at once
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        current = dummy
        # use != is much quicker than 'is not'
        while current.next != None and current.next.next != None:
            first = current.next
            second = current.next.next

            current.next = second
            first.next = second.next
            second.next = first

            current = current.next.next
        return dummy.next