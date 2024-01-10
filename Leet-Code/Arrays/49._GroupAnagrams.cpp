class Solution {
public:

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector <string> > v;
        map <string,vector<int>> map;

        for (int i = 0;i<strs.size();i++){
            string s =strs[i];
            sort(s.begin(),s.end());
            map[s].push_back(i);
            
        }
        

        
        for(auto i :map){
            vector<string> v1;
            for(auto j: i.second){
              v1.push_back(strs[j]);

            }
            v.push_back(v1);

        }
        return v;
    }
};