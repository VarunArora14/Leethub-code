class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>> diff;
        
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=1;j<words[i].length();j++)
            {
                int sub = words[i][j] - words[i][j-1];
                temp.push_back(sub);
            }
            diff.push_back(temp);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int val: diff[i])
                cout<<val<<" ";
            cout<<"\n";
        }
        
        // find the odd vector
        vector<int> temp = diff[0];
        
        int count=0, idx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]!=diff[i][j])
                {
                    count++;
                    idx=i;
                    break; // no point checking all indices
                }
            }
        }
        // cout<<count<<" "<<idx;
        
        if(count==n-1)
            return words[0];
        
        return words[idx];
    }
};

// Inorder to find the odd vector, we keep traversing the 2d vector with temp = diff[0]
// Each time on traversal, if we find the 2 vectors not same, we store idx=i and count++
// Since temp was diff[0], we check if count==n-1 i.e. it does not match remaining all vectors, ans was idx=0
// Otherwise, there will be only 1 time when temp[0] will not match and we store the idx=i so return words[i]

// consider ["abc", "aaa", "abc"], temp="abc"
// "abc" matches with "abc" (diff[0])
// "abc" does not match with "aaa", idx=1, count=1
// "abc" matches with "abc", END

// here count==1 which is not diff.size()-1 (2) so return words[i]

// if it was ["abc", "aaa", "aaa"], then temp!=diff[i] for any and then count==n-1 so we return words[0]