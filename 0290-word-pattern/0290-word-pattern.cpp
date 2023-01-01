class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> vec;
        set<string> seen;
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            vec.push_back(word);
        }
        
        if(vec.size()!=pattern.size()) return false;
        
        // we need to map pattern with word and word with pattern as 2 maps
        map<string, set<char>> m1;
        map<char, set<string>> m2;
        
        for(int i=0;i<vec.size();i++)
        {
            string str = vec[i];
            char key = pattern[i];
            
            m1[str].insert(key); // push character to string's pattern 
            m2[key].insert(str); // push the string to pattern's matching values
        }
        
        for(auto [key,val]: m1)
        {
            if(val.size()>1) return false;
        }
        
        for(auto [key,val]: m2)
        {
            if(val.size()>1) return false;
        }
        
        return true;
    }
};

// 2 conditions arise as false - 
// 1. 2 words have same pattern
// 2. 2 pattern[i] have same word in them