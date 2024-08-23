class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n= s.size();
        int maxlen = 0;
        map <char,bool> vis;
        while(i<n && j<n){
            if(!vis[s[j]]){
                vis[s[j]]=true;
                j++;
            }
            else{
                while(s[j]!=s[i]){
                    vis[s[i]] = false;
                    i++;
                }
                j++;
                i++;
            }


            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};