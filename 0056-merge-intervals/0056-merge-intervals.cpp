bool cmp(vector<int> &a,vector<int> &b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            vector<int> &top = ans.back();

            if(intervals[i][0]<=top[1]){
                top[1] = max(intervals[i][1],top[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;

    }
};