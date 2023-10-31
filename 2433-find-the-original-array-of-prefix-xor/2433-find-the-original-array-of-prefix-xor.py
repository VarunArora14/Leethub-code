class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        # using xor properties and logic, pref[i] = arr[0]^arr[1]^...arr[i] and 
        # pref[i+1] = arr[0]^arr[1]^....arr[i+1], pref[i]^pref[i+1]=arr[i+1]
        # pref[i]^pref[i-1]=arr[i]
        
        arr=[pref[0] for _ in range(len(pref))]
        for i in range(1, len(pref)):
            # print(i)
            arr[i] = pref[i] ^ pref[i-1]
        
        return arr