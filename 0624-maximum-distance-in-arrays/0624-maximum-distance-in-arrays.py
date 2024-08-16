class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min_vals = []
        max_vals = []
        
        for i,arr in enumerate(arrays):
            max_vals.append((arr[-1],i))
            min_vals.append((arr[0],i))
        
        # print(len(max_vals))
        max_vals.sort(key=lambda x: -x[0])
        min_vals.sort(key=lambda x: x[0])
        
        if max_vals[0][1] == min_vals[0][1]:
            return max(max_vals[0][0] - min_vals[1][0], max_vals[1][0] - min_vals[0][0])
        else:
            return max_vals[0][0] - min_vals[0][0]
            