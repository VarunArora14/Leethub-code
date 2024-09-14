# we want a subarray(consecutive nums) with largest bitwise & value
# for this we have to find the largest number and check how many consecutive maxnum exists

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        
        maxnum=0
        for num in nums:
            maxnum = max(maxnum, num)
        
        # find most number of consecutive numbers with value maxnum
        count=0
        maxCount=1
        for i in range(len(nums)):
            if nums[i]==maxnum:
                count+=1
                maxCount = max(maxCount, count)
            else:
                count=0
        
        return maxCount