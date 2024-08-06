class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()){
            return false;
        }
        map<int,int> m;

        for(int i=0;i<target.size();i++){
            m[target[i]]++;
            m[arr[i]]--;
        }

        for(auto i : m){
            if(i.second!=0){
                return false;
            }
        }
        
        return true;
    }
};