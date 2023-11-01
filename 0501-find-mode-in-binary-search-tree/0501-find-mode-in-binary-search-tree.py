# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def preorderFind(root, mapper={}):
            if root is None:
                return
            
            if root.val in mapper:
                mapper[root.val]+=1
            else:
                mapper[root.val]=1
            
            preorderFind(root.left)
            preorderFind(root.right)
            return mapper
        
        mapper = preorderFind(root)
        
        maxval=-1
        res=[]
        for key,val in mapper.items():
            if maxval<val:
                maxval=val
        # print(mapper)
        # print(maxval)
        for key,val in mapper.items():
            if val==maxval:
                res.append(key)
        
        return res