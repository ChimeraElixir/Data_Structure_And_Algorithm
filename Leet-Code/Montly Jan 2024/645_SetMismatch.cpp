class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        vector <int> v(nums.size()+1,0);
        vector <int> ans(2,0);
        for( int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        for(auto i:v){
            cout<<i;
        }
        for(int i=1;i<=nums.size();i++){
            
            if(v[i]==2){
                ans[0]=i;
            }          
            if(v[i]==0){
                ans[1]=i;
            }
        }
    
        
        return ans;
    }
};
