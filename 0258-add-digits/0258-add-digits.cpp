class Solution {
public:
    int digitSum(int num)
    {
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        long long curr=num;
        while(curr-9>0)
        {
            curr=digitSum(curr);
        }
        return curr;
    }
};