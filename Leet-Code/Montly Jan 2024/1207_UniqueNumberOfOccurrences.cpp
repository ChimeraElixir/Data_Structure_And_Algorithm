class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int,int> map;
        set <int> s;
        for (auto i:arr){
            map[i]++;
        }
        for(auto i:map){
            if(s.find(i.second)!=s.end()){
                return false;
            }
            else{
                s.insert(i.second);
            }
        }
        return true;
    }
};