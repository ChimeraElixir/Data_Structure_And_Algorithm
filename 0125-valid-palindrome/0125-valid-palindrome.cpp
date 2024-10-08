class Solution {
    private:
    bool alphanum(char a){
        return ('A'<=a && a<='Z') || ('a'<=a && a<='z') || ('0'<=a && a<='9');
    }
public:
    bool isPalindrome(string s) {
       int n = s.size();
       int i=0,j=n-1;
       while(i<j){
        while(i<j and !alphanum(s[i])){
            i++;
        }
        while(i<j and !alphanum(s[j])){
            j--;
        }
        if(tolower(s[i])!=tolower(s[j])){
            return false;
        }
        i++;
        j--;
       } 
       return true;
    }
};
