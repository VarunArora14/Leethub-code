class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j}); // water locations
                    vis[i][j]=1;
                }
                else count++;
            }
        }
        
        if(q.size()==0 || count==0) return -1;
        int res=0;
        
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto [row, col] = q.front();
                q.pop();
                
                for(auto dir: dirs)
                {
                    int r = row + dir[0];
                    int c = col + dir[1];
                    
                    if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0)
                    {
                        q.push({r,c});
                        vis[r][c] = vis[row][col]+1;
                        res = max(res, vis[r][c]);
                    }
                }
            }
        }
        
        // for(auto v: vis)
        // {
        //     for(auto vc: v) cout<<vc<<" ";
        //     cout<<"\n";
        // }
        
        return res-1;
    }
};

// better to start off with water and do bfs and check later the max value