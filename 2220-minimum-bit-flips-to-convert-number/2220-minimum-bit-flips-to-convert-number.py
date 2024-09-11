class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        
        # when we do xor of 2 numbers, same bits become 0 and diff bits stay 1
        xor_val = start ^ goal
        print(bin(xor_val)[2:])
        counter=0
        for x in bin(xor_val)[2:]:
            if x=='1':
                counter+=1
        return counter