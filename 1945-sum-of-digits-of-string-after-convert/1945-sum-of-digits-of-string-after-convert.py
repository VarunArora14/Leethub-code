class Solution:
    def getLucky(self, s: str, k: int) -> int:
        
        numbers = ''
        for char in s:
            numbers+=str(ord(char)-96) # 97 is for 'a'
        print(numbers)
        
        for i in range(k):
            if k==0 or len(numbers)==1:
                return int(numbers)
            digits = 0
            for char in numbers:
                digits+=int(char)
            numbers = str(digits)
            print(numbers)
        
        return int(numbers)