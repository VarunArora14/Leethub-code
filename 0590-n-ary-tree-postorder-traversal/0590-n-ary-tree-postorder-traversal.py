"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        def helper(root, arr):
            if root is None:
                return
            
            for child in root.children:
                helper(child, arr)
            
            arr.append(root.val)
        
        arr=[]
        helper(root, arr)
        
        return arr