class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        
        prefix_xor = [0 for _ in range(len(arr))]
        
        prefix_xor[0] = arr[0]
        
        for i in range(1, len(arr)):
            prefix_xor[i] = prefix_xor[i-1]^arr[i]
        
        res = []
        for q in queries:
            start=q[0]
            end=q[1]
            
            if start == 0:
               res.append(prefix_xor[end]) 
            else:
                res.append(prefix_xor[end]^prefix_xor[start-1])
        return res
        