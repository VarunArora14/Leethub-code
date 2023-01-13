class Solution {
    
    pair<int , int> solve(vector<int> adj[] , string &s , int par , int &ans , vector<bool> &vis)
    {
        priority_queue<int> pq ;
        
        vis[par] = 1 ;
        
        for(auto &x: adj[par])
        {
            if(!vis[x])
            {
                 pair<int , int> p1 = solve(adj , s , x , ans , vis) ;
                 if(p1.first != s[par]) // adjacent same char check
                 {
                     pq.push(-p1.second) ;
                     if(pq.size() > 2) pq.pop() ; // keep longest 2 lengths as think of them as left and right branches
                     // of a string which lead to ans
                 }
            }
        }
        
        int mxnum = 0;
        int curmx = 0 ;
        
        // cout<<pq.size()<<"\n";
        while(pq.size() > 0) // pq can have 1 or 2 elements so add accordingly 
        {
            int f = -pq.top() ;
            pq.pop() ;
            curmx+= f ; // store max length for each node
            
            mxnum = max(mxnum , f) ; // store longest length node to return 
        }
            
        
        curmx++ ; // add current node to ans with branches
        // cout<<"currmax: "<<curmx<<"\n";
        ans = max(ans,  curmx) ;
        
        return {s[par] , mxnum + 1 } ; // return the child character to check for adjacent 
        // and maxnum+1 is longest length we return as we decide later which length to size using pq
            
    }
    
public:
    int longestPath(vector<int>& parent, string s) {
        // NOTE - we just dont want adjacent chars to be same, we can multiple occurances in same string tho
        int n = parent.size() ;
        vector<int> adj[n] ;
        
        for(int i=1; i<n ; i++)
        {
            adj[i].push_back(parent[i]) ;
            adj[parent[i]].push_back(i) ;

        }

        vector<bool > vis(n , 0) ;
        
        int ans = 0;
        
        solve(adj , s , 0 , ans, vis) ;
        return ans ;
    }
};