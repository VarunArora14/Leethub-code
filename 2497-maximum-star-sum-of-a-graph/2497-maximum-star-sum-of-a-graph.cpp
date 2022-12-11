class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n=vals.size();
        vector<vector<int>> vec(n);
        
        for(auto edge: edges)
        {
            vec[edge[0]].push_back(edge[1]); 
            vec[edge[1]].push_back(edge[0]);
            // later we use these to get the values and then priority queue
        }
        
        int ans=INT_MIN;
        
        // traverse the vec
        for(int i=0;i<n;i++)
        {
            
            // make min heap
            priority_queue<int, vector<int>, greater<int>> pq;
            
            int node = vals[i]; // as node value has to be considered as well with edges
            
            for(int x: vec[i])
            {
                pq.push(vals[x]);
                if(pq.size() > k) pq.pop(); // maintain size k
            }
            
            // find the curr node-neighbour sum and then check the max
            while(!pq.empty())
            {
                if(pq.top() > 0) node+=pq.top();
                pq.pop(); // pop always
            }
            
            ans = max(node,ans);
        }
        
        return ans;
        
    }
};

// adding negative nbrs dont make sense as we need at most k