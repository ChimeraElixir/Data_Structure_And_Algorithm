class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int> newInterval = points[0];
        int ans = 1;
        for(int i=1;i<points.size();i++)
        {
            if( newInterval[1] >= points[i][0])
            {
                newInterval[0] = min(newInterval[0],points[i][0]);
                newInterval[1] = min(newInterval[1],points[i][1]);
            }
            else{
                ans++;
                newInterval = points[i];
            }
        }
     
        return ans;
    }
};