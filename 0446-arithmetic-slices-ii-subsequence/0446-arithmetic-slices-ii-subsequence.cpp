class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector< unordered_map<long, long> > dp(nums.size());
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                
                dp[i][diff]++;
                
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        
        return res;
    }
};

// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solutions/1455315/c-simple-and-short-dp-solution-with-explanation/

// the idea is to find for each index the {index, (diff, count)} 
// where for each element we mark the difference between 2 elements and store the count