//V1 using map
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map <int,int> map;
        vector<vector<int>> v={{},{}};
        

        for(auto i:matches){
             map[i[0]];
             map[i[1]]++;
        }
        for(auto i:map){
            if(i.second==0){
                v[0].push_back(i.first);
            }
            if(i.second==1){
                v[1].push_back(i.first);
            }
            cout<<i.first<<' '<<i.second<<endl;
        }
        
    return v; 

    }
};


//V2 using vectors

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> present(100001, 0);
        vector<int> losses(100001, 0);
        vector<vector<int>> ans(2);

        for (auto i : matches) {
            present[i[0]] = 1;
            present[i[1]] = 1;

            losses[i[1]]++;
        }

        for (int i = 0; i < 100001; i++) {
            if (present[i]) {
                if (losses[i] == 0) {
                    ans[0].push_back(i);
                }
                else if (losses[i] == 1) {
                    ans[1].push_back(i);
                }
            }
        }

        return ans;
    }
};
