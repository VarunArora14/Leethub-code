class Solution {
    public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        
        int cntOnes = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(c == '1') cntOnes++;
            else{
                int tmp1 = cntOnes;
                int tmp2 = res + 1;
                res =min(tmp1, tmp2);
            }
        }
        
        return res;
    }
};

// if c is 1, then it will not inpact the minFlips
// if c is 0, then 2 options we can do to make it mono incr
// 1. keep it as 0, and flip all the preceeding 1 to 0, need to know the count of ones so far
// 2. flip it to 1, will not need to do anything