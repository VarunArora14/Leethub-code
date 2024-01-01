class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort(reverse=True)
        s.sort(reverse=True)
        
        n = len(g)
        m = len(s)
        
        i=0
        j=0
        
        counter=0
        
#         keep moving to less greedy child if g[i] > s[i] which can be satisfied, till either cookies or child end
        while i<n and j<m:
            if g[i] > s[j]:
                i+=1
            elif g[i]<=s[j]:
                i+=1
                j+=1
                counter+=1
        
        return counter