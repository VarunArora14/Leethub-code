class Solution {
public:

long long ans=0;

    // this method returns the number of children of node 'nbr' including itself
    long long dfs(int src, int seats, vector<int>& vis, vector<vector<int>>& adj)
    {

        // mark this node as visited
        vis[src]=1;
        long long count=1; // 1 for current node

        for(auto x: adj[src])
        {
            if(vis[x]) continue; // avoid visiting same nodes like 1->2->1

            count+=dfs(x,seats,vis,adj); // count number of children of 'src' by doing dfs
        }

        // if count smaller then send just 1 car so 1km for backtracking to prev node from 'src'
        if(count<=seats)
            ans+=1;

        else{
            // send more cars for next node distance during backtracking
            // long long cars = ceil(count/(seats*1.0)); // we need ceil so mulriply by 1.0
            // or do below as alternative to ceil. We need ceil for case count=8, seats=3 where we need 3 cars but 8/3=2
            long long cars = (count+seats-1)/seats;
            ans+=cars; // these many cars will travel 1km more as we backtrack so we store result of previous values
        }

        return count; // as we backtrack to prev node, we need number of children of that node for computing again
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size();
        vector<vector<int>> adj(n+1);

        for(auto road: roads)
        {
            int u=road[0];
            int v=road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n+1);
        vis[0]=true; // capital as start of DFS

        for(auto nbr: adj[0])
        {
            dfs(nbr,seats,vis,adj);
        }

        return ans;
    }
};
// we want farthest node to be allocated seat first so we do DFS to reach the last node
// from that node we backtrack sitting in the next car if seats are not full 

// we maintain depth we are at from capital(0) and distance required if seats full = depth