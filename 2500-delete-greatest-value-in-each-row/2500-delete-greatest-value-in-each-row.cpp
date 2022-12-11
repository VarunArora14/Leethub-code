class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<priority_queue<int>> vec(n);
        
        for(int i=0;i<n;i++)
        {
            for(int node: grid[i])
            {
                vec[i].push(node);
            }
        }
        
        int ans=0;
        
        while(!vec[0].empty())
        {
            int curr=0;
            // for each row the max top value
            for(int i=0;i<n;i++)
            {
                curr = max(curr, vec[i].top());
                vec[i].pop();
            }
            ans+=curr;
        }
        
        return ans;
    }
};