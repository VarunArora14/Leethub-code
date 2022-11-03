class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> um;
        int count=0;
        bool flag=true;
        for(string word: words)
        {
            um[word]++;
        }
        // cout<<count;
        // now we have mapped non-palindromic strings and their occurences
        for(string key: words)
        {
            string rev = key;
            reverse(rev.begin(), rev.end());
            
            // more than 1 'aa'
            if(key==rev && um[key]>1)
            {
                // same like 'aa', 'bb'
                um[key]-=2;
                count+=4;
            }
            else if(key!=rev && um[key]>0 && um[rev]>0)
            {
                um[key]--;
                um[rev]--;
                count+=4;
            }
            else if(flag==true && key==rev && um[key]>0)
            {
                flag=false; // cant add more self palindromes as mid 'lc aa cl', cant add 'bb'
                count+=2;
                um[key]--;
            }
        }
        return count;
    }
};

// If there are multiple self palindromes, consider adding them in pairs
// If word and reverse(word) exists, reduce their occurence and do count+=4
