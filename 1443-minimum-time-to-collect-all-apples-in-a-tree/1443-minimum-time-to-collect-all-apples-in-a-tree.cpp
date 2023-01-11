class Solution {
public:
    int dfs(int src, vector<bool>& hasApple, vector<int>& vis, vector<vector<int>>& adj)
    {
        int nbrSum=0, totalSum=0;
        vis[src]=true;
        
        // go till last node with no nbrs to go to
        for(auto nbr: adj[src])
        {
            if(!vis[nbr])
            {
                nbrSum = dfs(nbr, hasApple, vis, adj); // sum of each nbr of src node
                
                // for leafs, nbrSum=0, for apples we add +2 and also for backtracking while nbrSum contains sum from
                // nbr to leaf. Check apple of each nbr and return sum based on that
                if(hasApple[nbr] || nbrSum) totalSum+=nbrSum+2;
            }
        }
        vis[src]=false;
        return totalSum;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        // if Apple at 0, the ans is 0 as we dont have to traverse
        return dfs(0,hasApple, vis, adj);
    }
};
// each time we reach an apple, we want to return the ans from that position and if nbr as an apple, it is in path
// so add childSum+2 while backtracking