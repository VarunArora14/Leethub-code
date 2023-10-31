class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        
        # doing in inplace
        temp = pref[0]
        for i in range(1,len(pref)):
            prevPref = pref[i]
            pref[i] = pref[i]^temp
            temp = prevPref
        
        return pref