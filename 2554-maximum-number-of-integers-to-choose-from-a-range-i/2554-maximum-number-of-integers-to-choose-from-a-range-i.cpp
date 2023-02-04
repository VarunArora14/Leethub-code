class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxsum) {
        
        unordered_set<int> b(banned.begin(), banned.end());
        int count=0;
        long long sum=0;
        for(int i=1;i<=n && sum+i<=maxsum;i++)
        {
            if(!b.count(i))
            {
                count++;
                sum+=i;
            } 
        }
        
        return count;
    }
};