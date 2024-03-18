bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        stack<vector<int>>s;
        s.push(intervals[0]);

        for(int j=1;j<intervals.size();j++){
            vector<int> &top=s.top();
            vector<int> curr=intervals[j];
            if(curr[0]<=top[1]){
                top[1]=max(curr[1],top[1]);
            }
            else{
                s.push(curr);
            }
        }

        vector<vector<int>> mergedIntervals;
        while (!s.empty()) {
            mergedIntervals.insert(mergedIntervals.begin(), s.top());
            s.pop();
        }  
        return mergedIntervals;
    }
};