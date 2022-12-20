class Solution {
public:
    int lca(int a, int b) {
        int numa = 0; int numb = 0;
        while(a != b) {
            if(a < b) {
                b /= 2;
                numb++;
            } else if(a > b) {
                a /= 2;
                numa++;
            }
        }
        return numa + numb + 1;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& q: queries) {
            int a = q[0];
            int b = q[1];
            ans.push_back(lca(a, b));
        }
        return ans;
    }
};