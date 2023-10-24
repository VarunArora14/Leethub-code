# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        q = []
        q.append(root)
        res = []  
        
        while len(q) or len(temp):
            temp=[]
            maxval = float('-inf')
            for _ in range(len(q)):
                top = q[0]
                maxval = max(maxval, top.val)
                q=q[1:]
                
                if top.left is not None:
                    temp.append(top.left)
                if top.right is not None :
                    temp.append(top.right)
            q=temp
            res.append(maxval)
            
        return res
                
            