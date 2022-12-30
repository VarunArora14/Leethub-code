class Solution {
public:
    set<vector<int>> ans;
    
    void dfs(vector<vector<int>>& graph, vector<int> vis, vector<int> temp, int src)
             {
                 temp.push_back(src);
                 vis[src]=true;
                 
                 if(src == graph.size()-1)
                 {
                     // if last element reached
                     ans.insert(temp);
                     return;
                 }
                 
                 for(auto nbr: graph[src])
                 {
                     // make sure not to go in cycle
                     if(vis[nbr]==false)
                        dfs(graph, vis, temp, nbr); // pass this nbr as next node
                 }
             }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> vis(n);
        vector<int> temp;
        
        
        for(auto nbr: graph[0])
        {
            dfs(graph, vis, temp, 0);
        }
        
        vector<vector<int>> ret;
        for(auto ele: ans) ret.push_back(ele);
        return ret;
    }
};

// apply dfs and store the current path and add to ans vector each time, keep a vis vector for each path as well