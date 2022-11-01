class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans;
        
        // traverse the column for each ball
        for(int j=0;j<n;j++)
        {
            int row=0, col=j;
            while(row<m)
            {
                if(grid[row][col]==1)
                {
                    // check for right(col+1) if 1 or last ele
                    if(col==n-1 || grid[row][col+1]==-1)
                    {
                        ans.push_back(-1);
                        break;
                    }
                    col++; // as we move right
                }
                else{
                    // if current row,col-1 is -1 check col-1
                    if(col==0 || grid[row][col-1]==1)
                    {
                        ans.push_back(-1);
                        break;
                    }
                    col--;
                }
                row++; // at each iteration
            }
            // once we have reached the last row if row==m, push the col as position 
            if(row==m)
                ans.push_back(col); // not when row less than m it means it is -1
        }
        return ans;
    }
};
/*
for each ball we look at right if curr is 1 and left if curr is -1. If curr and right 1 or curr and left -1 then we can go next row else not. For first column and last column we have to decide differently as we can't go left or right in them.

We have to go down the path which is like DFS and can be done in that way
https://leetcode.com/problems/where-will-the-ball-fall/discuss/988244/C-%2B%2B-Easy-Solution-oror-DFS

Here we di iterative, for each we traverse check right if 1 and left if -1 and if cannot reach end push -1
If we reach the last row we push that column as the ans as all have to reach the last
*/