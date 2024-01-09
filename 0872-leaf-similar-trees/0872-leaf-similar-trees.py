# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def postOrderLeaves(root, res:List[int]):
            if root is None:
                return
            
            postOrderLeaves(root.left,res)
            postOrderLeaves(root.right, res)
            
            if root.left is None and root.right is None:
                res.append(root.val)
        
        r1,r2 = [],[]
        postOrderLeaves(root1,r1)
        postOrderLeaves(root2,r2)
        
        # print(r1)
        # print(r2)
        
        return r1==r2