class Solution:
    def singleNumber(self, nums: List[int]) -> int:
      mapper = {}
      for num in nums:
        if num not in mapper:
          mapper[num]=1
        else:
          mapper[num]+=1


      for key, val in mapper.items():
        if val==1:
          return key


      return 0
    
# Above is incorrect, Correct Solution
# https://leetcode.com/problems/single-number-ii/discuss/43302/Accepted-code-with-proper-Explaination.-Does-anyone-have-a-better-idea