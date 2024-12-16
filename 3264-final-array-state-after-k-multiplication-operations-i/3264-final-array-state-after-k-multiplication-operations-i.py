class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        
        while k:
            small_idx = 0
            for i,num in enumerate(nums):
                if num<nums[small_idx]:
                    small_idx = i
            nums[small_idx] = nums[small_idx]*multiplier
            k-=1
        
        return nums
            