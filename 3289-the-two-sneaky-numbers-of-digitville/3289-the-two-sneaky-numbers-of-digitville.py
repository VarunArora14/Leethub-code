class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        res = []
        s = set()
        for num in nums:
            if num in s:
                res.append(num)
            else:
                s.add(num)
        return res