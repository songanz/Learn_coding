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
        head = pointer = ListNode(0)
        node_val_list = []
        for l in lists:
            while l:
                node_val_list.append(l.val)
                l = l.next

        node_val_list.sort()

        for i in node_val_list:
            pointer.next = ListNode(i)
            pointer = pointer.next

        return head.next


if __name__ == "__main__":
    s = Solution()

    h1 = ListNode(1)
    h2 = ListNode(2)
    h3 = ListNode(4)
    h1.next = h2
    h2.next = h3

    l1 = ListNode(1)
    l2 = ListNode(3)
    l3 = ListNode(4)

    l1.next = l2
    l2.next = l3

    print(s.mergeKLists([h1, l1]))
