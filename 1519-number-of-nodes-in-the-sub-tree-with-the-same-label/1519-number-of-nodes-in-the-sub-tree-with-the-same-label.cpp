class Solution {
public:
    vector<int> helper(int src, vector<int>& vis, vector<vector<int>>& adj, string& labels, vector<int>& ans)
    {
        vis[src] = true;
  vector<int> mapper(26);
  int src_char_index = labels[src] - 'a'; // the character whose count we have to increase
  mapper[src_char_index] = 1;
  // store 1 for current and add the sum for children instead of later doing mapper[src_char_index]++ as later
  // traversal will contain prev answers
  for (auto nbr : adj[src])
  {
    if (!vis[nbr])
    {
      vector<int> childCounter = helper(nbr, vis, adj, labels, ans);
      for (int i = 0; i < 26; i++)
      {
        mapper[i] += childCounter[i]; // add below values
      }
    }
  }

  // src is the node index
  ans[src] = mapper[src_char_index];
  vis[src] = false; // backtracking
  return mapper;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        vector<int> vis(n,0);
        helper(0, vis, adj, labels, ans);

        return ans;
    }
};