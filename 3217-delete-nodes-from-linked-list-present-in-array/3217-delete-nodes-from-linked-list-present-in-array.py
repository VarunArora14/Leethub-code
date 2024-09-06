# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        curr = dummy
        s = set()
        for num in nums:
            s.add(num)
        
        
        while head:
            if head.val not in s:
                curr.next = head
                curr = curr.next
            
            head=head.next
        curr.next = None
        
        return dummy.next