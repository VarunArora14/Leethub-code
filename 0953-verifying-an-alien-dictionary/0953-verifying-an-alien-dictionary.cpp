class Solution {
public:
    bool isIncreasing(string& w1, string& w2, unordered_map<char,int>& um)
    {
        int i=0, j=0;
        while(i<w1.length() && j<w2.length())
        {
            if(um[w1[i]]==um[w2[j]])
            {
                i++;
                j++;
                continue;
            }
            else if(um[w1[i]]>um[w2[j]]) return false;
            else return true;
        }
        
        if(i<w1.length()) return false; // first word bigger in len
        else return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int> um;
        for(int i=0;i<order.length();i++)
        {
            char ch = order[i];
            um[ch]=i;
        }
        
        for(int i=0;i<words.size()-1;i++)
        {
            if(!isIncreasing(words[i], words[i+1], um)) return false;
        }
        return true;
    }
};