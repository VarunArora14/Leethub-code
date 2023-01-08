class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        if(n<=2) return n;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<double, int> slopeVsPointsMap;
            int samePoint=1;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0] == points[j][0])
                {
                    slopeVsPointsMap[INT_MAX]++; // inf slope when dx=0 from dy/dx
                }
                else if(points[i][1] == points[j][1] && points[i][0] == points[j][0])
                {
                    samePoint++;
                }
                else{
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    slopeVsPointsMap[slope]++;
                }
            }
            
            int maxLocalSameSlope=0;
            for(auto [key,val]: slopeVsPointsMap)
            {
                maxLocalSameSlope = max(maxLocalSameSlope, val);
            }
            maxLocalSameSlope+=samePoint;
            ans = max(ans, maxLocalSameSlope);
        }
        return ans;
    }
};