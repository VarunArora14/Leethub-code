class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        newarr=[]
        for i in range(n):
            Sm=0
            for j in range(i,n):
                Sm+=nums[j]
                newarr.append(Sm)
            
        newarr.sort()
        mod=10**9+7
    
        return sum(newarr[left-1:right])%mod