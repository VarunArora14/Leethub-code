# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return head
        prev = head
        
        while head and head.next:
            newNode = ListNode(gcd(head.val, head.next.val))
            nex = head.next
            head.next = newNode
            newNode.next = nex
            head = nex
        
        return prev