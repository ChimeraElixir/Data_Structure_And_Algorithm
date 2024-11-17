class Solution {
    private:
        bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<int> &check){
            path[node] = 1;
            check[node] = 0;
            for(auto adj:graph[node]){
                if(!vis[adj]){
                    vis[adj] = 1;
                    if(dfs(adj,graph,vis,path,check)==true){
                        return true;
                    }
                }
                else if(path[adj]){
                    return true;
                }
            }
            path[node] = 0;
            check[node] = 1;
            return false;
        }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);


        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(i,graph,vis,path,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};