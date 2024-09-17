# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        l = ListNode(-1)
        temp = l
        c1,c2 = l1,l2
        csum=0
        carry=0
        while c1 and c2:
            csum=(c1.val+c2.val+carry)%10
            carry = (c1.val + c2.val + carry)//10
            l.next = ListNode(csum)
            l=l.next
            c1=c1.next
            c2=c2.next
        
        while c1:
            csum = (c1.val+carry)%10
            carry = (c1.val+carry)//10
            l.next = ListNode(csum)
            l=l.next
            c1=c1.next
        
        while c2:
            csum = (c2.val+carry)%10
            carry = (c2.val+carry)//10
            l.next = ListNode(csum)
            l=l.next
            c2=c2.next
        
        if carry:
            l.next = ListNode(carry)
        
        return temp.next