class Solution {
public:
    int helper(int node, vector<bool> &hasApple, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[node] = true;

  int childTime = 0, ans = 0;
  for (auto nbr : adj[node])
  {
    // ans+=helper(nbr, hasApple, ans);
    if (!vis[nbr])
    {
      childTime = helper(nbr, hasApple, adj, vis);

      if (childTime || hasApple[nbr])
        ans += childTime + 2;
    }
  }

  vis[node] = false;
  return ans;
}
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
  vector<vector<int>> adj(n);
  vector<int> vis(n);

  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return helper(0, hasApple, adj, vis);
  // return ans;
}
};

// whenever we find apple, return true from that position and add that as 1 in ans while backtracking