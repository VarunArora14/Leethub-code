class Solution {
public:
    int res=0;
    void backtrack(vector<string>& words,vector<int>& score,vector<int>&count,vector<int>& used,int idx,int curr_res)
    {
        for(int i=0;i<26;i++)
        {
            if(used[i]>count[i])
                return;
        }
        res=max(res,curr_res);
        for(int i=idx;i<words.size();i++)
        {
            for(auto &ch:words[i])
            {
                used[ch-'a']++;
                curr_res+=score[ch-'a'];
            }
            backtrack(words,score,count,used,i+1,curr_res);
            for(auto &ch:words[i])
            {
                used[ch-'a']--;
                curr_res-=score[ch-'a'];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> count(26,0),used(26,0);
        for(auto &ch:letters)
        {
            count[ch-'a']++;
        }
        backtrack(words,score,count,used,0,0);
        return res;
    }
};