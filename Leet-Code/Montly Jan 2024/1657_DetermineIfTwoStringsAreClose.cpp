class Solution {
public:
    bool closeStrings(string s, string t) {
        vector <int> v1(26,0),v2(26,0);

        for(auto i:s) v1[i-'a']++;
        for(auto i:t) {
            if(v1[i-'a']<=0){
                return false;
            }
            v2[i-'a']++;
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2;
    }
};
