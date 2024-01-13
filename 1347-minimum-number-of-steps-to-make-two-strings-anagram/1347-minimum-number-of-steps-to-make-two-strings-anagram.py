class Solution:
    def minSteps(self, s: str, t: str) -> int:
        
        # store occurence of all elements of s and then see missing in t
        # if there are extra elements in t but not in s, they will be replaced as per calculation
        # our desired state is to reach characters and count matching s from t
        
        s_mapper = {}
        for char in s:
            if char in s_mapper:
                s_mapper[char]+=1
            else:
                s_mapper[char]=1
        
        t_mapper = {}
        for char in t:
            if char in t_mapper:
                t_mapper[char]+=1
            else:
                t_mapper[char]=1
        
        total_diff=0
        for key,value in s_mapper.items():
            diff_key = 0
            if key in t_mapper:
                diff_key = max(0, value - t_mapper[key])
            else:
                diff_key = value
            total_diff+=diff_key                
        
        return total_diff