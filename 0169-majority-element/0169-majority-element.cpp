class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int element;
        int count=0;

        for(auto i:v){
            if (count==0){
                count=1;
                element=i;
            }
            else if(i==element) count++;
            else count--;
        }
        return element;
        
    
    }
};