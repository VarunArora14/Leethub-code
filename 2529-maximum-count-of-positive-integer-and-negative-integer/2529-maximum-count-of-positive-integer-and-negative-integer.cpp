class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int negative_counter=0, positive_counter=0;
        for(int num: nums)
        {   
            if(num==0) continue;
            if(num>0) positive_counter++;
            else negative_counter++;
        }
        return max(positive_counter, negative_counter);
    }
};