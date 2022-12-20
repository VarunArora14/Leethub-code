class Solution {
public:
    void dfs(int src, vector<int>& vis, vector<vector<int>>& rooms)
    {
        for(int nbr: rooms[src])
        {
            if(vis[nbr]==0)
            {
                vis[nbr]=1;
                dfs(nbr, vis, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int> vis(n);
        
        vis[0]=1;
        dfs(0, vis, rooms);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) return false;
        }
        
        return true;       
        
    }
};