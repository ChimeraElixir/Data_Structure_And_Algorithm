class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m ;
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int ans = 0;
        for(auto i:nums){
            if(!s.count(i-1)){
                int count = 1;
                int element = i+1;
                while(s.count(element)){
                    count++;
                    element++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};