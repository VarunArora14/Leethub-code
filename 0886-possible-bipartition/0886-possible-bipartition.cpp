class Solution {
public:
    
    bool bipartite(int src, vector<vector<int>>& adj, vector<int>& colors)
    {
        colors[src]=1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            
            for(auto nbr: adj[front])
            {
                if(colors[nbr]==0)
                {
                    colors[nbr] = -colors[front];
                    q.push(nbr); // IMP
                }
                else if(colors[nbr] == colors[front]) // compare with front not src
                {
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);
        
        for(auto dislike: dislikes)
        {
            int u=dislike[0];
            int v=dislike[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> colors(n+1, 0); // n+1 not n
        
        // graph can be disconnected
        for(int i=1;i<=n;i++)
        {
            if(colors[i]==0)
            {
                bool ans=bipartite(i, adj, colors);
                if(ans==false) return false;
            }
        }
        return true;
    }
};

// treat the dislikes as edges in the graph and visualise assigning them groups named 1 and -1, we can see bipartite is being applied