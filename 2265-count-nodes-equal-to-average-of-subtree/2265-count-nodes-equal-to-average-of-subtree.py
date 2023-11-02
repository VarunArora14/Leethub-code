# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        arr = []

        def postOrderFind(root, arr:list)->(int,int):
            if root is None:
                return 0,0
            
            lsum, lcount = postOrderFind(root.left,arr)
            rsum, rcount = postOrderFind(root.right, arr)
            
            subtreeSum = lsum + rsum
            subtreeNodeCount = lcount + rcount
            
            if root.val == (subtreeSum + root.val) // (subtreeNodeCount+1):
                arr.append(root.val)
            
            return (subtreeSum+root.val, subtreeNodeCount+1)
        
        postOrderFind(root,arr)
        return len(arr)
            