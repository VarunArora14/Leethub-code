class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        mapper = {}
        
        n = len(s)
        
        res=-1
        for i in range(n):
            if s[i] not in mapper:
                mapper[s[i]] = [i]
            else:
                mapper[s[i]].append(i) # store the indices
        
        for val in mapper.values():
            # print(val)
            if len(val)>1:
                res = max(res, val[-1]-val[0]-1) # last - first idx - 1(for len, consider "aa")
        
        return res