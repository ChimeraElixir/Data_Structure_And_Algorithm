class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> frequency(26,0);
        for(auto i:s){
            frequency[i-'a']++;
        }
        string ans="";
        for(auto i:order){
            for( int j=0;j<frequency[i-'a'];j++){
                ans+=i;
            }
            frequency[i-'a']=0;
        }
        for(int i=0;i<26;i++){
            if(frequency[i]!=0){
                for( int j=0;j<frequency[i];j++){
                    ans+=char(i+'a');
                }
                
            }
            
        }
        return ans;
    }
};