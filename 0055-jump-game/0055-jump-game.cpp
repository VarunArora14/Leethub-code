class Solution {
    vector<int> memo;
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=true;
        // dp[i] means check reachability to i, 0 base case
        for(int i=1;i<n;i++){
            // check if possible way from j to reach i and if yes then break
             for(int j=i-1;j>=0;j--){
                 // if j reachable and from j we can go further to or more than i then yes
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
  }
};