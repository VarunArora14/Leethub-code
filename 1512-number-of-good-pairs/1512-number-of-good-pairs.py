class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        goodPairs=0
        n = len(nums)
        for i in range(n):
            for j in range(0,i):
                if nums[i]==nums[j]:
                    goodPairs+=1
        return goodPairs