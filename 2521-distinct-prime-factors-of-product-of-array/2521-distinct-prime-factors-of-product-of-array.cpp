class Solution {
public:
    
    void findPrimeFactors(int num, set<int>& s)
    {
        int c=2;
        while(num>1)
        {
            if(num%c==0){
                s.insert(c);
                num=num/c;
            }
            else c++;
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primeFactors;
        for(int num: nums)
        {
            findPrimeFactors(num, primeFactors);
        }
        
        return primeFactors.size();
    }
};

// basically we have to find the numbers in nums which have unique prime numbers