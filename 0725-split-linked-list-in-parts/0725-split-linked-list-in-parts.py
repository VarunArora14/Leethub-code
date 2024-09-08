# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        node_arr = []
        curr = head
        
        while curr:
            node_arr.append(curr.val)
            curr = curr.next
        
        if len(node_arr) < k:
            res=[]
            curr = head
            while k:
                if curr:
                    newNode = ListNode(curr.val)
                    curr = curr.next
                    res.append(newNode)
                else:
                    res.append(None)
                k-=1
        else:
            res = []
            rem = len(node_arr)%k # these will be arrays with 1 extra node
            factor = len(node_arr)//k
            node_sizes = [factor for _ in range(k)]
            i=0
            while rem:
                node_sizes[i]+=1
                i+=1
                rem-=1
                
            print(node_sizes)
            curr = head
            for i in range(len(node_sizes)):
                newHead = ListNode(curr.val) if curr else None
                t = newHead
                curr = curr.next
                for j in range(1,node_sizes[i]):
                    t.next = ListNode(curr.val)
                    t=t.next
                    curr = curr.next
                res.append(newHead)
        return res