class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial;
        vector<char> list;
        int j=1;
        for(int i=1;i<=n;i++){
            factorial.push_back(j);
            list.push_back('0'+i);
            j*=i;
        }
        reverse(factorial.begin(),factorial.end());
        for(auto i:factorial){
            cout<<i;
        }
        cout<<endl;
        k--;

        string s;
        for(int i=0;i<n;i++){
            int no = k/factorial[i];
            s+=list[no];
            list.erase(list.begin() + no);
            k=k%factorial[i];
        }

        return s;
        
    }
};