class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        for(int i = 0; i < s.length(); ++i) {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        for(int i = 0; i < s.length(); ++i) {
            if( mp1[s[i]] != t[i] || mp2[t[i]] != s[i] ) {
                return false;
            }
        }
        return true;
    }
};