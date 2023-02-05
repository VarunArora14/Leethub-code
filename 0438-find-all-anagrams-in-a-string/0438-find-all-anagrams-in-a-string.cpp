class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m1(26,0);
        
        if(p.length()>s.length()) return {};
        int n=p.length();
        for(char ch:p)
        {
            int idx = ch-'a';
            m1[idx]++;
        }
        
        int start=0,end=0;
        vector<int> ans;
        
        vector<int> m2(26,0);
            while(end<n)
            {
               int idx = s[end]-'a';
                m2[idx]++;
                end++;
            }
            if(compare(m1,m2))
                ans.push_back(start);
        
        
        for(end=n;end<s.length();end++)
        {
            cout<<"start is "<<start<<" end is "<<end<<"\n";
            m2[s[start]-'a']--; // remove s[start]-'a' value so that we remove 'c' not 'a'
            // if we do m[start]-- we reduce value of a count, For reducing c value, we have to store it's idx as
            // int i = s[start]-'a' and then do m2[i]--
            start++;
            int idx=s[end]-'a';
            m2[idx]++;
            
            if(compare(m1,m2))
                ans.push_back(start);
        }
        return ans;
    }
    
    bool compare(vector<int>& m1, vector<int>& m2)
    {
        for(int i=0;i<26;i++)
        {
            if(m1[i]!=m2[i])
                return false;
        }
        return true;
    }
};
/*
we take the first n chars, where n is p.length(), push in a map and compare the 2 maps by using equal(m1,m2) by map<char,int> having 26 chars all initially at 0
*/