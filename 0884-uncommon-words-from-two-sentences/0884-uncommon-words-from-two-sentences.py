class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        res = []
        m1,m2 = {}, {}
        for word in s1.split(" "):
            if word not in m1:
                m1[word]=0
            m1[word]+=1
        
        for word in s2.split(" "):
            if word not in m2:
                m2[word]=0
            m2[word]+=1
        
        for k,v in m1.items():
            if v==1 and k not in m2:
                res.append(k)
        
        for k,v in m2.items():
            if v==1 and k not in m1:
                res.append(k)
        
        return res