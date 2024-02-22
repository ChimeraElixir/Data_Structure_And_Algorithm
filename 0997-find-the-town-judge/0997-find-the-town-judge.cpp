class Solution {
    private:
    bool knows(vector<vector<int>> &v,int a,int b){
        if(v[a][b]==1){
            return true;
        }
        return false;
    }
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    vector<vector<int>> v(N+1,vector<int>(N+1,0));

    for(auto i:trust){
        v[i[0]][i[1]]=1;
    }
    stack <int> s;

    for(int i=1;i<N+1;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        if(knows(v,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans=s.top();
    s.pop();

    for(int i=1;i<N+1;i++){
        if(i==ans){
            continue;
        }
        if(v[i][ans]!=1){
            return -1;
        }
    }
    for(int i=1;i<N+1;i++){
        if(v[ans][i]!=0){
            return -1;
        }
    }
    return ans;


    }    
};