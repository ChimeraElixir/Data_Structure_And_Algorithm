class DisjointSet{
    vector<int> parent,size;
    int extra = 0;

    public:
        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
                size[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(findParent(u) == findParent(v)){
                extra++;
                return;
            }
            if(size[pu]>size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else{
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
        int getExtra(){
            return extra;
        }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        // for(int i=0;i<n;i++){
            for(auto j :connections){
                // cout<<j[0]<<endl;
                ds.unionBySize(j[0],j[1]);
            }
        // }

        int components = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i){
                components++;
            }
        }

        int extra = ds.getExtra();

        if(extra >= components-1){
            return components-1;
        }
        return -1;
    }
};