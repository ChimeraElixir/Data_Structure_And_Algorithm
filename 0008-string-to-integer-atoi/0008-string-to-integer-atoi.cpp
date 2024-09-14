class Solution {
public:
    int myAtoi(string s) {
        double  ans=0;
        int i=0;
        int size=s.size();
        if(size==0){
            return 0;
        }
        
        while(i<size && s[i]==' '){
            i++;
        }
        
        bool negative=0;
        if(s[i]=='-'){
            negative=1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
          
        while(i  < size && s[i]>='0' && s[i]<='9' ){
            ans=(ans*10);
            ans+=int(s[i]-'0');
            i++;
        
        }
            
        if(negative){
            ans= -ans;
        }
        if(ans>INT_MAX){
            return INT_MAX;
        }
        else if(ans<INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
};