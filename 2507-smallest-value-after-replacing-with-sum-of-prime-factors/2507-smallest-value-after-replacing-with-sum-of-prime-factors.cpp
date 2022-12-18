class Solution {
public:
    
    int primeSum(int num)
    {
        int sum=0;
        while(num>1)
        {
            for(int i=2;i<=num;i++)
            {
                if(num%i==0)
                {
                    cout<<i<<" ";
                    sum+=i;
                    num=num/i;
                    break;
                }
            }
        }
        cout<<"\n";
        return sum;
    }
    int smallestValue(int n) {
        
        while(n!=primeSum(n))
        {
            n=primeSum(n);
        }
        
        return n;
    }
};