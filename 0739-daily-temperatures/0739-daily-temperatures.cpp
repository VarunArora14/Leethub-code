class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans;
        stack<int> st;
        
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            
            if(st.empty())
                ans.push_back(0);
            else ans.push_back(st.top()-i);
            
            st.push(i); // push index as we need "number of days we have to wait"
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// check from last element and start pushing in stack
// base case, last element and is 0 and push it