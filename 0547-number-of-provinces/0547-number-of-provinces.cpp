class DisjointSet{
    vector<int> parent,size;
    
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i] = 1;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
            
        }
        
        void unionBySize(int u , int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv) return;
            
            if(size[pu]>size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else{
                parent[pu] = pv ; 
                size[pv] += size[pu];
            }
        }
        int answer(int V){
            int ans = 0;
            for(int i=0;i<V;i++){
                if(parent[i]==i){
                    ans++;
                }
            }
            return ans;
        }
        
};

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
        
        //******** DisJointSet *********//

        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i){
                ans++;
            }
        }
        
        return ans;


        //******** DFS ********//

        // vector<int> visited(n,0);

        // int count = 0;

        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         dfs(i,isConnected,visited,n);
        //         count++;
        //     }
    
        // }
        // return count;
    }
};