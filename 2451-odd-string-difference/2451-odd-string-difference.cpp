class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words.size();
        
        vector<vector<int>> diff(n);
        for(int i=0;i<n;i++)
        {
            int len = words[i].length();
            vector<int> temp;
            for(int j=1;j<len;j++)
            {
                int sub = words[i][j] - words[i][j-1];
                temp.push_back(sub);
            }
            diff[i]=temp;
        }
        
        
        map<vector<int>, int> um;
        map<vector<int>, int> idmap;
        
        // store the index, occurences as the value of map and key is the diff vector
        for(int i=0;i<n;i++)
        {
            um[diff[i]]++;
            idmap[diff[i]]=i;
        }
        
        for(auto [key,val]: um)
            if(val==1)
            {
                int idx = idmap[key];
                return words[idx];
            }
        
        return "";
    }
};