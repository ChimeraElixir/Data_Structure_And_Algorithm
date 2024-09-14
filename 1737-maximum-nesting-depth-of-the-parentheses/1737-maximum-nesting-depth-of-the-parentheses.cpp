class Solution {
public:
    int maxDepth(string s) {
        int balance =0 ;
        int ans=0;
        for(auto i :s){
            if(i=='('){
                balance++;
                ans=max(ans,balance);
            }
            else if(i==')'){
                balance--;
            }
        }
        return ans;
    }
};