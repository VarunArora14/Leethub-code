class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> um;
        for(auto task: tasks)
        {
            um[task]++;
        }
        
        int ans=0;
        for(auto [key,val]: um)
        {
            if(val>1 && val%3!=0)
            {
                // number can be 3n+1 or 3n+2, 3n+1 can be written as 3(n-1) + 2*2 => (n-1+2 = n+1 steps)
                // consider examples (4,5), (7,8), (10,11) to see the pattern
                ans+=val/3+1; // as n+1 steps
            }
            else if(val>1 && val%3==0)
            {
                ans+=val/3;
            }
            else return -1;
        }
        return ans;
    }
};

// each number can be taken from num%2 and num%3 to get correct ans unless the number is 1
// example = num=4, ans=[2,2], num=5, ans=[2,3]