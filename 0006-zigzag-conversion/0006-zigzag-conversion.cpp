class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        int count=0;
        int row=0;
        vector<vector<char>> vec(numRows);
        while(count<n)
        {
            row=0;
            while(row<numRows && count<n)
            {
                vec[row].push_back(s[count]);
                count++;
                row++;
            }
            row=numRows-2;
            while(row >0 && count<n)
            {
                vec[row].push_back(s[count]);
                count++;
                row--;
            }
        }

        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(char val: vec[i])
                ans+=val;
            cout<<"\n";
        }

        return ans;
    }
};