class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s)<=10:
            return []
        
        n = len(s)
        mapper = dict()
        
        # if n=11, run 2 times as range(2)
        for i in range(0,n-9):
            substr = s[i:i+10]
            if substr in mapper:
                mapper[substr]+=1
            else:
                mapper[substr]=1
        
        res = []
        for key, val in mapper.items():
            if val > 1:
                res.append(key)
        
        return res