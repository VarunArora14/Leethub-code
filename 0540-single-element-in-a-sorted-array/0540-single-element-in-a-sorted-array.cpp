class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            // for even check right for valid and for odd check left, if not then either mid is the one or on left
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid; // mid is candidate ans as we didnt check whether mid has left or right same value or not
        }
        
        return nums[left];
    }
};