class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>count;
        for(auto i:nums){
            count[i]++;
        }
        priority_queue<pair<int,int>> P1;
        for(auto i:count){
            P1.push(make_pair(i.second,i.first));
        }
        vector<int> final_;
        for(int i=0;i<k;i++){
            cout<<P1.top().first<<" "<<P1.top().second<<endl;
            final_.push_back(P1.top().second);
            P1.pop();
        }

        return final_;
    }
    
};