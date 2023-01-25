class Solution {
public:
    void bfs(vector<int>& dist, int src, vector<int>& edges, int n)
    {
        queue<int> q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            // check if node points to another element(not -1) and it is not visited before(cycle check)
            if(edges[front]!=-1 && dist[edges[front]]==INT_MAX)
            {
                q.push(edges[front]); // next node which is being pointed to
                dist[edges[front]]=dist[front]+1; // inc the distance +1 from node it is being pointed from
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        
        // store dist from node1 to all others possible in dist1 and dist2
        bfs(dist1, node1, edges, n);
        bfs(dist2, node2, edges, n);
        
        int res=INT_MAX, node=-1; // for finding the dist and the node(base case -1)
        
        for(int i=0;i<n;i++)
        {
            // both reachable from node1 and node2
            if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX)
            {
                if(res > max(dist1[i], dist2[i]))
                {
                    node=i;
                    res = max(dist1[i], dist2[i]);
                }
            }
        }
        return node;
    }
};
// do bfs from both nodes and whichever node u reach, store in that node the distance it requires to go from node1 to 
// that node. Do this for both node1 and node2, storing them in vectors and then later check if for the same
// edge we were able to reach from both n1 and n2 then store res = max({dist1[i], dist2[j]}) (not res as res is bigger)