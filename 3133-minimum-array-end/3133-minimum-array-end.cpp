class Solution {
public:
    long long minEnd(int n, int x) {
        
        n-=1;
        long long a=x;
        while (n!=0){
            a = (a+1) | x;
            n-=1;
        }
        return a;
    }
};