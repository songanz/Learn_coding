# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not (l1 or l2):
            return []
        elif not l1:
            head = ListNode(l2.val)
        elif not l2:
            head = ListNode(l1.val)
        else:
            if l1.val < l2.val:
                head = ListNode(l1.val)
            else:
                head = ListNode(l2.val)

        nodelist = [head]

        pointer_l1 = l1
        pointer_l2 = l2

        while pointer_l1 or pointer_l2:
            if not pointer_l1:
                nodelist[-1].next = pointer_l2
                nodelist.append(pointer_l2)
                return nodelist[1]
            elif not pointer_l2:
                nodelist[-1].next = pointer_l1
                nodelist.append(pointer_l1)
                return nodelist[1]
            else:
                if pointer_l1.val < pointer_l2.val:
                    temp = ListNode(pointer_l1.val)
                    nodelist[-1].next = temp
                    nodelist.append(temp)
                    pointer_l1 = pointer_l1.next
                else:
                    temp = ListNode(pointer_l2.val)
                    nodelist[-1].next = temp
                    nodelist.append(temp)
                    pointer_l2 = pointer_l2.next

        return nodelist[1]


if __name__ == "__main__":
    s = Solution()

    h1 = ListNode(1)
    h2 = ListNode(2)
    h3 = ListNode(4)
    # h4 = ListNode(4)
    # h5 = ListNode(5)
    h1.next = h2
    h2.next = h3
    # h3.next = h4
    # h4.next = h5

    l1 = ListNode(1)
    l2 = ListNode(3)
    l3 = ListNode(4)

    l1.next = l2
    l2.next = l3

    print(s.mergeTwoLists(h1, l1))
