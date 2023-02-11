#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        // create a adjacency list with color as well along with node connected to u-> {v, color}
  vector<vpii> graph(n); // n vectors of vector<pair<int,int>>

  for (auto r : red)
  {
    int u = r[0];
    int v = r[1];
    graph[u].pb({v, 1});
  }

  for (auto b : blue)
  {
    int u = b[0];
    int v = b[1];
    graph[u].pb({v, -1});
  }

  // now we need to store the shortest distances using bfs
  vi dist(n, -1), vis(n, 0);
  queue<tuple<int, int, int>> q; // {node, distance, color}
  q.push({0, 0, 0});             // initial color is 0

  while (!q.empty())
  {
    auto [node, distance, color] = q.front();
    q.pop();

    dist[node] = dist[node] == -1 ? distance : dist[node]; // if old distance is -1, we assign distance value passed otherwise we have shortest distance

    for (auto &[nbr_node, nbr_color] : graph[node])
    {
      // if same color as nbr or if nbr_node already visited, ignore
      if (nbr_color == color || nbr_node==-1)
        continue;

      q.push({nbr_node, distance + 1, nbr_color}); // new element as nbr with +1 distance and other color
      nbr_node=-1;
    }
  }
  return dist;
    }
};