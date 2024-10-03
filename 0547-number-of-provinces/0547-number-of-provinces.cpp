class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited,int n){
        visited[node] = 1;
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[node][i]==1){
                dfs(i,isConnected,visited,n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> visited(n,0);

        int count = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited,n);
                count++;
            }
    
        }
        return count;
    }
};