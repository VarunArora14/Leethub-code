class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        
        int m=queries.size();
        vector<int> res(m,1); // for the new added edges
        
        
        for(int i=0;i<m;i++)
        {
            int f = queries[i][0];
            int s = queries[i][1];
            
            // find LCA of both and add each edge to res[i] as query result
            while(f!=s)
            {
                if(f>s) f=f/2;
                else s=s/2;
                
                res[i]++;
            }
        }
        
        return res;
    }
};

// when 2 edges are connected, the length of cycle is found by going to parent of both nodes and doing count++ and adding +1 for the
// added edge