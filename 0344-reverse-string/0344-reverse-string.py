class Solution:
    def reverseString(self, s: List[str]) -> None:
        sz = len(s)
        for i in range(0, sz//2):
            temp = s[i]
            s[i] = s[sz-i-1]
            s[sz-i-1] = temp