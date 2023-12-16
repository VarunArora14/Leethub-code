class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m1 = {}
        m2 = {}
        
        for letter in s:
            if letter in m1:
                m1[letter]+=1
            else:
                m1[letter]=1
        
        for letter in t:
            if letter in m2:
                m2[letter]+=1
            else:
                m2[letter]=1
        
        return m1==m2
        