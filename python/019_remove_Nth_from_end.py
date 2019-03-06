# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        temp = head
        num = 1
        nodeList = [head]

        if head.next == None:
            return []

        while temp.next is not None:
            temp = temp.next
            num += 1
            nodeList.append(temp)

        if num == n:
            return nodeList[1]

        nodeList[num - n - 1].next = nodeList[num - n].next

        return head


if __name__ == "__main__":
    s = Solution()

    h1 = ListNode(1)
    h2 = ListNode(2)
    h3 = ListNode(3)
    h4 = ListNode(4)
    h5 = ListNode(5)
    h1.next = h2
    h2.next = h3
    h3.next = h4
    h4.next = h5

    print(s.removeNthFromEnd(h1, 2))
