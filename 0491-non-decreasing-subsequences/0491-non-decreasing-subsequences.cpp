class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int n=nums.size();
        set<vector<int>> res;
        
        // bitmask traverse, i from 1 to ignore empty set
        for(int i=1; i < (1<<n); i++)
        {
            vector<int> seq;
            // j for checking the jth bit true or not
            for(int j=0;j<n;j++)
            {
                // check if jth bit is true in bitmask "i"
            if (((i >> j) & 1) == 1)
            {
                seq.push_back(nums[j]);
            }
            }
            
            // for the subset check if valid or not
            if (seq.size() >= 2) {
                // check whether the sequence is increasing
                bool isIncreasing = true;
                for (int i = 0; i < seq.size() - 1; i++) {
                    isIncreasing &= seq[i] <= seq[i + 1];
                }
                if (isIncreasing) {
                    res.insert(seq);
                }
            }
        }
        return vector(res.begin(), res.end());
    }
};
// we have to generate all subsets using bitmasking and then check the vector if increasing