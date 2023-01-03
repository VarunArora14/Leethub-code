class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n=strs.size();
        
        vector<vector<char>> vec(m, vector<char>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch = strs[j][i];
                vec[i].push_back(ch);
            }
        }
        
        int count=0;
        
        
        for(auto v: vec)
        {
            auto temp = v;
            sort(temp.begin(), temp.end());
            if(temp!=v) count++;
        }
        
        return count;
    }
};