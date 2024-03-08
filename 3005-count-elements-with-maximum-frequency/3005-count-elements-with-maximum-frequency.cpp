class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101,0);
        for(auto i:nums){
            v[i]++;
        }
        int maximum=*max_element(v.begin(),v.end());
        int count=0;
        for(auto i:v){
            if(i==maximum){
                count++;
            }
        }
        return count*maximum;
    }
};