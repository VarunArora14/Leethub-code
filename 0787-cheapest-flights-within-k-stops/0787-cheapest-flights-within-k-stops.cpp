using vi =vector<int>;
using vpii = vector<pair<int,int>>;
class Solution {
public:
    
    void dfs(int src, int dest, int k, int cost, unordered_map<int, vpii> &mp, int& ans, vi &vis)
{
  // base cases
  if (src == dest)
  {
    ans = cost;
    return;
  }
  if (k == 0)
    return;

  vis[src] = 1;

  for (auto e : mp[src])
  {
    if (vis[e.first] == 0)
    {
      // reduce fn calls
      if (cost + e.second > ans)
        continue;
        
        // cout<<"cost: "<<cost<<"\n";

      dfs(e.first, dest, k - 1, cost + e.second, mp, ans, vis);
    }
  }

  vis[src] = 0;
}
    
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty()) {
            int sz = q.size();
            // Iterate on current level.
            while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] ==INT_MAX ? -1 : dist[dst];
    }
};