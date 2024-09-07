class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <int> st;
        int n = num.size();
        string s;
        for(int i=0;i<n;i++){
            while(!st.empty() && k && num[i]-'0' < num[st.top()]-'0'){
                st.pop();
                k--;
            }
            st.push(i);
        } 
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0"; 
        }
        while(!st.empty()){
            s.push_back(num[st.top()]);
            st.pop();
        }
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                s.pop_back();
            }
            else{
                break;
            }
        }
        if(s.empty()) return "0";
        reverse(s.begin(),s.end());
        return s;
    }
};