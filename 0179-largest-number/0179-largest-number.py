class LargerNumKey(str):
    def __lt__(x, y):
        # Compare x+y with y+x in reverse order to get descending order
        return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        strnums = [str(num) for num in nums]
        strnums.sort(key=LargerNumKey)
        print(strnums)
        res = ''.join(sn for sn in strnums)
        return '0' if res[0]=='0' else res
    