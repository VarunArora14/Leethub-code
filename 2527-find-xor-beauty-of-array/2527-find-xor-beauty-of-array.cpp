class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans=0;
        for(int n: nums)
            ans = ans^n;
        return ans;
    }
};
// the key observation is that triplets i,j,k occur in pairs which lead to cancelling of those numbers
// except the case i=j=k which is number nums[i] itself, therefore we take xor of all 