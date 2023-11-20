class Solution:
    def partitionString(self, s: str) -> int:
        cur = ""
        count = 0

        for i in s:
            if i not in cur:
                cur += i
            else:
                count += 1
                cur = i
        return count+1