class Solution {
public:

int maxPoints(vector<vector<int>> &points) {
    int result = 0;
    for(int i = 0; i < points.size(); i++){
        int samePoint = 1;
        unordered_map<double, int> map;
        for(int j = i + 1; j < points.size(); j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                samePoint++;
            }
            else if(points[i][0] == points[j][0]){
                map[INT_MAX]++;
            }
            else{
                double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                map[slope]++;
            }
        }
        int localMax = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += samePoint;
        result = max(result, localMax);
    }
    return result;
}
};

 /*
     *  A line is determined by two factors,say y=ax+b
     *  
     *  If two points(x1,y1) (x2,y2) are on the same line(Of course). 

     *  Consider the gap between two points.

     *  We have (y2-y1)=a(x2-x1),a=(y2-y1)/(x2-x1) a is a rational, b is canceled since b is a constant

     *  If a third point (x3,y3) are on the same line. So we must have y3=ax3+b

     *  Thus,(y3-y1)/(x3-x1)=(y2-y1)/(x2-x1)=a

     *  Since a is a rational, there exists y0 and x0, y0/x0=(y3-y1)/(x3-x1)=(y2-y1)/(x2-x1)=a

     *  So we can use y0&x0 to track a line;
     */