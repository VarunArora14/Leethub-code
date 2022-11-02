class Solution {
public:
    
    bool check(string& first, string& second)
    {
        int diff=0; // same length=8
        for(int i=0;i<first.length();i++)
        {
            if(first[i]!=second[i])
                diff++;
        }
        return diff==1; // true for 1, else false
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
     
        int count=0;
        queue<string> q;
        int n=bank.size();
        vector<bool> vis(n);
        q.push(start);
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string curr = q.front();
                q.pop();
                if(curr==end)
                    return count;
                
                for(int i=0;i<n;i++)
                {
                    if(vis[i]==0)
                    {
                        bool single_diff = check(curr, bank[i]);
                        if(single_diff==true)
                        {
                            q.push(bank[i]);
                            vis[i]=true;
                        }
                    }
                }
            }
            if(!q.empty())
            count++;
        }
        
        return -1;
    }
};
// we have to take the 'start' and then compare the elements with bank if not visited then find those with difference=1
// and add to queue using bfs and count++
// if we find q.front() == end, we return count else -1