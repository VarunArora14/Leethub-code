class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = [(nums[i],i) for i in range(len(nums))]
        nums.sort()
        start=0
        end=len(nums)-1
        while start<end:
            if nums[start][0]+nums[end][0]==target:
                return [nums[start][1], nums[end][1]]
            elif nums[start][0]+nums[end][0]>target:
                end-=1
            else:
                start+=1
                