class Solution:
    def findComplement(self, num: int) -> int:
        binary_num_str = bin(num)[2:]
        
        new_num=''        
        
        for b in binary_num_str:
            if b=='1':
                new_num+='0'
            else:
                new_num+='1'
        return int(new_num,2)