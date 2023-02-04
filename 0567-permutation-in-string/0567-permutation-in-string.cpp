class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1,m2;
        if(s1.length()>s2.length()) return false;
        
        for(char ch: s1) m1[ch]++;
        
        int start=0, i=0;
        for(i=0;i<s1.length();i++)
        {
            m2[s2[i]]++;
        }
        // i now at s1.length() idx
        
        for(i;i<s2.length();i++)
        {
            
            if(m1==m2) return true;
            m2[s2[start]]--; // remove start element as go forward in window
            if(m2[s2[start]]==0) m2.erase(s2[start]); // erase 0 value for proper map comparisons
            start++;
            m2[s2[i]]++; // add i+1 character from prev
        }
        if(m1==m2) return true;
        
        return false;
    }
};
// we can't sort s2(2nd example)
// we have to consider a window/substring which is like map where we add and remove prev characters based 
// on number of occurences and find if substring exists
