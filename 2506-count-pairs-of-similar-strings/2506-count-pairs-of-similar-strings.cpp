class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int ans=0;
        vector<set<char>> v;
        for(string word: words)
        {
            set<char> s;
            for(char ch: word)
            {
                s.insert(ch);
            }
            v.push_back(s);
        }
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i]==v[j]) ans++;
            }
        }
        return ans;
    }
};