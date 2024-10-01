class Solution {
public:
    static bool comp( pair<int,double> a ,pair<int,double> b){
        if(a.first==b.first) return a.second > b.second;
        else{
            return a.first > b.first;
        }
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> temp;

        for(int i=0;i<position.size();i++){
            temp.push_back({position[i],(double)((target-position[i])*1)/(speed[i]*1.0)});
        }

        sort(temp.begin(),temp.end(),comp);

        for(pair<int,double> i:temp ){
            cout<<i.first<<" "<<i.second<<endl;
        }

        double max = 0;
        int count = 0;
        for (int i=0;i<temp.size();i++){
            if(temp[i].second>max){
                max = temp[i].second;
                count++;
            }
        
        }
        return count;
    }
};