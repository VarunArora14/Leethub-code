class Solution:
    def reverseWords(self, s: str) -> str:
        strings = s.split(" ")
        res = ""
        # traverse backwards
        for string in strings:
            string = string[::-1] # reverse the single string
            res+=string + " "
        res = res[:len(res)-1]
        return res