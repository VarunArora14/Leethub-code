class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(auto interval: intervals)
        {
            if(ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            
            else{
                ans.back()[1] = max(ans.back()[1], interval[1]); // chang ending of last element and not insert
            }
        }
        return ans;
    }
};