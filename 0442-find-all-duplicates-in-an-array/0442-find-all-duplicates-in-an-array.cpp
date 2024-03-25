#include <bitset>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        bitset<100001> bit; 
        for (auto i:nums){
            if(bit.test(i)){
                ans.push_back(i);
            }
            else{
                bit.set(i,1);
            }
        }
        return ans;
    }
};