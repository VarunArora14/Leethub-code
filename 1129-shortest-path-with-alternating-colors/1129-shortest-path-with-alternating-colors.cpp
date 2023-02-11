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
vector<vector<int>> adj[n];

for (int i = 0; i < red.size(); i++)
{

    int u = red[i][0];
    int v = red[i][1];

    adj[u].push_back({v, 0});
}
for (int i = 0; i < blue.size(); i++)
{

    int u = blue[i][0];
    int v = blue[i][1];

    adj[u].push_back({v, 1});
}

vector<int> distance(n, -1);
distance[0] = 0;

queue<vector<int>> pq;
vector<vector<int>> visited(n, vector<int>(2, 0));

pq.push({0, 0, -1});

visited[0][0] = 1;
visited[0][1] = 1;

while (!pq.empty())
{
    int node = pq.front()[1];
    int nodeWeight = pq.front()[0];
    int nodecolor = pq.front()[2];

    pq.pop();

    for (auto itr : adj[node])
    {
        int adjNode = itr[0];

        int color = itr[1];

        if (visited[adjNode][color] == 0 and color != nodecolor)
        {
            if (distance[adjNode] == -1)
                distance[adjNode] = nodeWeight + 1;
            pq.push({nodeWeight + 1, adjNode, color});

            visited[adjNode][color] = 1;
        }
    }
}

return distance;
    }
};

// we have to use 2d visited as we have 2 colors and we can come back to same node if different color path
// exists like red = [[0,1]] and blue = [[0,1]]