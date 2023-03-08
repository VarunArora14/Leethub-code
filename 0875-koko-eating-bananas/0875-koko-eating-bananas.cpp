class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=*max_element(piles.begin(), piles.end()); // with 1e10 it gives out of range int error for total, try it
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            int total=0;
            // check for mid bananas per hour if less than h
            for(int p:piles)
            {
                total+=(p+mid-1)/mid; // if m=2 and p=3 then it takes 2 hours to eat 3 bananas
                // 1.0*p works somehow. You can also use total+=(p+mid-1)/mid which also works same for ceil. Check it out
                if(total>h) break; // gives weird error about overflow of value of int in total so break it
            }
            
            // if more hrs taken than h then increase lower bound so mid increases
            if(total>h)
            {
                lo=mid+1;
            }
            else hi=mid-1; // if total more than h then decrease the upper bound
        }
        return lo; // return lower bound always as it returns min value for satisfying the condition
        
        // Time is O(Nlog(MaxP))
    }
};