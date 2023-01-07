class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        
        vector<long long> costs(c.begin(), c.end());
        sort(costs.begin(), costs.end());
        for(int i=1;i<costs.size();i++)
        {
            costs[i] +=costs[i-1];
        }
        
        if(coins<costs[0]) return 0;
        for(int i=1;i<costs.size();i++)
        {
            if(coins<costs[i]) return i;
        }
        
        return costs.size();
    }
};
// just sort the costs and 