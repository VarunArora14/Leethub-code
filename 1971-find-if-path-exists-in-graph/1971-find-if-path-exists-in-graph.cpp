class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
                
        vector<int> adj[n];
        
        for(auto edge: edges)
        {
            int u = edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n);
        
        vis[src]=1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            for(auto nbr: adj[front])
            {
                if(!vis[nbr])
                {
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        
        return vis[dest]==true;
        
        
    }
};

// to find valid path btw src and destination, simply do bfs from src