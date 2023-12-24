class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        char = "0"
        temp1 = ""
        temp2=""
        flag = True
        for i in range(n):
            flag = not flag
            if flag:
                temp1+="0"
                temp2+="1"
            else:
                temp1+="1"
                temp2+="0"
        
        d1, d2 = 0,0
        
        for i in range(n):
            if temp1[i]!=s[i]:
                d1+=1
            if temp2[i]!=s[i]:
                d2+=1
        print(f"temp1: {temp1}, temp2: {temp2}")        
        return min(d1,d2)
        