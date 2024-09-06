class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                ans.push_back(arr[i]);
            }
            else{
                while(!ans.empty() && ans.back()>0 && ans.back() < abs(arr[i])){
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back()==abs(arr[i])){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back()<0){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;

        // stack <int> p;
        // stack <int> n;
        // vector<int> ans;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]>0){
        //         p.push(arr[i]);
        //     }
        //     else{
        //         n.push(arr[i]);
        //     }
        //     while(!p.empty() && !n.empty()){
        //         int pos = p.top();
        //         p.pop();
        //         int neg = n.top();
        //         n.pop();
        //         if(pos>abs(neg)){
        //             p.push(pos);
        //         }
        //         else if(pos < abs(neg)){
        //             n.push(neg);
        //         }
                
        //     }
        // }
        // while(!p.empty()){
        //     ans.push_back(p.top());
        //     p.pop();
        // }
        // while(!n.empty()){
        //     ans.push_back(n.top());
        //     n.pop();
        // }
        // reverse(ans.begin(),ans.end());

        // return ans;  
        
    }
};