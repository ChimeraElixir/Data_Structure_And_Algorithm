class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[left]){
                left++;
                nums[left] = nums[i];
            }
        }
        return left+1;
    }
};