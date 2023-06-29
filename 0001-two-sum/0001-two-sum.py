class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      n = len(nums)

      s = dict()

      for i in range(0,n):
        rem = target - nums[i]
        if rem in s.keys():
          return [i, s[rem]]

        s[nums[i]]=i # store the element as key and value as the index