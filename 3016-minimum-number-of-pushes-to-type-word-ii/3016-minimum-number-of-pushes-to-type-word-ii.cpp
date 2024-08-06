class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26);
        for(auto i : word){
            v[(i-'a')]++;
        }

        sort(v.begin(),v.end(),greater<int>());

        for(int i=0;i<26;i++){
            cout<<v[i];
        }

        int factor = 0;
        int ans = 0;
        
        for(int i=0;i<26;i++){
            if(i%8==0){
                factor++;
            }
            ans += v[i]*factor;
        }
        return ans;
    }
};