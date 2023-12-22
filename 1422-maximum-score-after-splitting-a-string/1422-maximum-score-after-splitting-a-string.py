class Solution:
    def maxScore(self, s: str) -> int:
        
        # at each position we count the number of 0s/1s and then take max of (zeros[i] + ones[i+1])
        zeros = [0 for _ in range(len(s))]
        ones = [0 for _ in range(len(s))]
        z=0
        o=0
        
        for idx, char in enumerate(s):
            if char == "0":
                z+=1
            zeros[idx] = z
        
        for i in range(len(s)-1, -1, -1):
            if s[i] == "1":
                o+=1
                ones[i]=o
        
        
        # print(zeros)
        # print(ones)
        
        maxval=0
        
        for i in range(len(s)-1):
            maxval = max(zeros[i] + ones[i+1], maxval)
            if maxval == 6:
                print(i)
        
        return maxval
        