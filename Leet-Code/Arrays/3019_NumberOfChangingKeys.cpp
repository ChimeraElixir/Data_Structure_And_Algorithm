class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        
        char a= tolower(s[0]);
        for (int i=1;i<s.size();i++){
            if(tolower(s[i])!=a){
                count++;
                a=tolower(s[i]);
            }
        }
        return count;
        
    }
};