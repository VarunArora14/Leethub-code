# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(root, res):
            if root == None:
                return
            
            if root.left:
                inorder(root.left, res)
    
            res.append(root.val)
            
            if root.right:
                inorder(root.right, res)
        
        res = []
        inorder(root,res)
        return res