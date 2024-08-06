#include <string>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto i : details){
            string s = i.substr(11,2);
            int tmp = stoi(s);
            if(tmp>60){
                count++;
            }
        }
        return count;
    }
};