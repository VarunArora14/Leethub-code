class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> in(n+1), out(n+1);
        for(auto t: trust)
        {
            int personWhoTrusts = t[0];
            int personTrusted = t[1];
            in[personTrusted]++;
            out[personWhoTrusts]++;
        }
        
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(in[i]==n-1 && out[i]==0) ans=i;
        }
        
        return ans;
    }
};

// inorder means trusted and outorder means out[i]=x means ith person trusts x people