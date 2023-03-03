class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()) return -1;
        
        int m=haystack.length(), n=needle.length();
        
        for(int i=0;i<=m-n;i++)
        {
            int j;
            for( j=0;j<n;j++)
            {
                if(haystack[i+j]!=needle[j]) break;
            }
            
            if(j==n) return i; // position found
        }
        return -1;
    }
};