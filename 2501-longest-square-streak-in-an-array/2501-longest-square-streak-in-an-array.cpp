class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int ans=0;
        unordered_set<int> us;
        
        for(int num: nums)
        {
            us.insert(num);
        }
        
        for(int num: nums)
        {
            int power=1, count=0;
            unsigned long long curr = num;
            if(curr==1) continue;
            
            while(us.count(curr))
            {
                count++;
                curr = curr*curr;
            }
            
            ans = max(ans, count);
            
        }
        if(ans==1) return -1;
        return ans;
    }
};