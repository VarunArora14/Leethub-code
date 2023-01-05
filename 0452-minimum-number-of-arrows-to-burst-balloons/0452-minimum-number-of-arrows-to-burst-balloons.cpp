class Solution {
public:
    static bool compare(vector<int>& p1, vector<int>& p2)
    {
        if(p1[0]==p2[0]) return p1[1]<p2[1]; // take smaller ending if same starting
        return p1[0]<p2[0]; // smaller starting otherwise
    }
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), compare);
        
        // for(auto v: p) cout<<v[0]<<" "<<v[1]<<"\n";
        cout<<"\n";
        int lastpoint = p[0][1];
        int ans = 1;
        for(auto point : p) {
            if(point[0] > lastpoint) {
                // cout<<point[0]<<" ";
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1],lastpoint);
            // cout<<"lastpoint now: "<<lastpoint<<"\n";
        }
        return ans;
    }
};
// the ques basically is a version of verlapping intervals where we have to overlap the intervals and reduce them
// to rigid ones

// if there are points like [2,8] , [3,10] and [9,12], the ans is 2 as we remove [3,10] as it overlaps but [9,12] does
// not overlap with [2,8]

// as we have sorted, inorder for overlaps to happen, the starting point of next point must be > ending point
// of previous otherwise it overlaps with prev

// we had to maintain the minimum end position to get the correct ans by condition =>
//  if(p.first > minEnd) {count++; minEnd = p.second;} which means that if we can burst 

// the reason we maintain just the lastpoint is bcos as we find overlapping intervals we have to understand that
// all balloons in the intervals with burst if the point chosen would be <= smallest endpoint of the interval
// otherwise we have to shoot more arrows

// Consider [ [1,10], [2,5], [6,7] ]
// here we need 2 arrows as 5 is smaller endpoint than 6, so now we maintain this lastpoint for each interval
// and once bigger starting point comes, do ans++, latpoint = next_ending_point and each time make
// lastpoint = min(point[1], lastpoint) to maintain smaller end point