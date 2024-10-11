class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m ;
        
        for(auto i:nums){
            m[i]++;
        }
        int ans = 0;
        for(auto i:nums){
            if(m.find(i-1)==m.end()){
                int count = 1;
                int element = i+1;
                while(m.find(element)!=m.end()){
                    count++;
                    element++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};