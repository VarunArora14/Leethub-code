class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_min=0, curr_max=0, max_ans=nums[0], min_ans=nums[0], total_sum=0;
        
        for(int num: nums)
        {
            total_sum+=num;
            curr_max = max(curr_max+num, num); // subarray vs single element max 
            max_ans = max(max_ans, curr_max);
            curr_min = min(curr_min+num, num);
            min_ans = min(min_ans, curr_min);
        }
        
        int ans = max_ans>0? (max(max_ans, total_sum-min_ans)): max_ans;
        return ans;
    }
};

// twice the array wouldnt make sense as we have double the ans, better approach is to find min and max sum of the
// array and later check ans = max(max_ans, total_sum-min_ans)
// if the max sum lies in borders(start and end) then it will come through total_sum - min_ans
// otherwise through max_ans which is largest subarray sum