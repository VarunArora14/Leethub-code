class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mapper = {}
        for num in nums:
            if num not in mapper:
                mapper[num]=1
            else:
                mapper[num]+=1
        
        res=0
        for key,val in mapper.items():
            if val==1:
                return -1
            elif val%3==0:
                res+=val/3
            elif val%3==2:
                res+=1+(val-2)/3
            else:
                res+=2 + (val-4)/3 # works for cases val>=4, we find if we substract 4, we get multiple of 3
        return int(res)
# since we consider val%3 before, consider cases where val%3==1 => [4,7,11,13,16,19,22..]
# in all the elements, notice if you reduce 4 from it, you will get a multiple of 3
# they way it works is that as val%3==1 => val-1%3==0 => but we cannot substract 1 from it and so, as the number
# is in form 3n+1, when we do 3n+1-4, we get 3(n-1) which is a multiple of 3
# and since we want to find as many 3 pairs for minimum operations, above logic works well