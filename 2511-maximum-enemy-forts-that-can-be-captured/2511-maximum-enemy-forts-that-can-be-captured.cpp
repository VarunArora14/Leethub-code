class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans=0;
        for(int i=0, j=0;i<forts.size();i++)
        {
            if(forts[i]!=0)
            {
                if(forts[j]==-forts[i]) 
                {
                    ans = max(ans, abs(i-j-1));
                }
                j=i; // store index of i in j always for next encounter of 1 or -1
            }
        }
        return ans;
    }
};
// basically we have to count number of 0s between 1 and -1 and ques is framed poorly for that
// as you can go from your fort to empty fort conquering all in the path, you have to find max you conquered
// case like [1,0,0,-1,0,1] has ans of 2 and not 3 as we have -1 in between