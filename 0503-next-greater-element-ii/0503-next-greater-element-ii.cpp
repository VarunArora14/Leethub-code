class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        // insert in reverse as we start checking from last element
        for(int i=n-1;i>=0;i--)
        {
            st.push(nums[i]);
        }
        
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]>=st.top())
                st.pop();
            
            if(st.empty())
                ans.push_back(-1);
            
            else ans.push_back(st.top()); // as now st.top() > nums[i]
            
            st.push(nums[i]); // for nums[i-1], current is a candidate to the stack
        }
        
        // ans stored values from n-1 to 0, so we reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};