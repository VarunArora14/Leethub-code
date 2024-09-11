class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        
        # when we do xor of 2 numbers, same bits become 0 and diff bits stay 1
        xor_val = start ^ goal
        
        counter=0
        while xor_val:
            if xor_val & 1:
                counter+=1
            xor_val = xor_val>>1
        return counter