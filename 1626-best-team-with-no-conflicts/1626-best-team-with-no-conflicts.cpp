class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
                
        vector<pair<int,int>> vec;
        vector<int> ans(scores.size()); // store the longest non-decreasing subsequence
        
        for(int i=0;i<scores.size();i++) {
            vec.push_back({ages[i], scores[i]});  // Push {age, score} pair in the array
        }
        
        sort(vec.begin(), vec.end());
        
        int sum=0;
        
        // similar to LIS
         for(int i=0; i<vec.size();i++) {
            ans[i]=vec[i].second; 
            for(int j=0;j<i;j++) {
                if(vec[i].second >= vec[j].second) {
                    ans[i] = max(ans[i], ans[j] + vec[i].second);
                }
            }
            sum = max(sum, ans[i]);
        }
        
        return sum;
        
    }
};

// as we have to pick a window/subarray of elements based on the condition and we have 1000 amx value, we can run 2 loops
// for checking all subarrays

// Validation: for a subarray of size>2, check if any element with ages[i]. Wouldn't work as 10^6 for loop
// and 10^3 for validation inside the loop

// Here we have a sequence/subsequence which we have to find which has to be increasing as in 2nd case we took the 1's
// as they had same values but did not take 2nd age[i]=2 as other was bigger in score