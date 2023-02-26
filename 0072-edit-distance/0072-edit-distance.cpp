using vvi = vector<vector<int>>;
using vi = vector<int>;
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
  vvi dp(n + 1, vi(m + 1, -1)); // n+1*m+1

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      // base case 1
      if (i == 0)
        dp[i][j] = j; // min operations left=j as crossed 0th idx for i

      // base case 2
      else if (j == 0)
        dp[i][j] = i; // crossed 0th idx so remaining operations=i

      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1]; // same characters so continue with prev ans

      else
      {
        dp[i][j] = 1 + min({dp[i - 1][j - 1], // replace
                            dp[i][j - 1],     // insert(j-1 changes to j but i remains same, means inserted in s1)
                            dp[i - 1][j]});   // delete(i-1 changes to i but j remains same means we go to next i position or delete an element in s1)
      }
    }
  }

  return dp[n][m];
    }
};