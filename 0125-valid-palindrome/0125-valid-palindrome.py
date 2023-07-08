class Solution:
    def checkPalindrome(self, s:str):
      print(s[::-1])
      return s == s[::-1]
    
    def isPalindrome(self, s: str) -> bool:
        allowed = '1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
        new_s=''
        for ch in s:
            if ch!=' ' and ch in allowed:
                new_s+=ch

        new_s = new_s.lower()
        return self.checkPalindrome(new_s)