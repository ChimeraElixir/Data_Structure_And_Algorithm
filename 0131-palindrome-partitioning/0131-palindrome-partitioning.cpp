class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int idx,int n,vector<string> &temp,vector<vector<string>> &ans,string s){
        if(idx==n){
            ans.push_back(temp);
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,n,temp,ans,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp ;
        solve(0,n,temp,ans,s);
        return ans;
    }
};