class Solution {
public:
    int minSteps(string s, string t) {
        vector <int> v1(26,0),v2(26,0);
        for (auto i:s) v1[i-'a']++;
        for (auto i:t) v2[i-'a']++;

        int count=0;

        for (int i=0;i<26;i++){
            if(v1[i]>v2[i]) count+=v1[i]-v2[i];
        }
        return count;
    }
};
