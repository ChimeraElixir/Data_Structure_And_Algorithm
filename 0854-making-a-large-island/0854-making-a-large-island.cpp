class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for (int row = 0; row < n; row++) {
            parent[row] = row;
            size[row] = 1;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int getSize (int node) {
        return size[node];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int di[] = {-1, 0};
        int dj[] = {0, -1};

        DisjointSet ds(n * m);

        // Creating Disjoint Set

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    for (int k = 0; k < 2; k++) {

                        int nrow = row + di[k];
                        int ncol = col + dj[k];

                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                            grid[nrow][ncol] == 1) {

                            int node = row * m + col;
                            int adjnode = nrow * m + ncol;

                            if (ds.findParent(node) != ds.findParent(adjnode)) {
                                ds.unionBySize(node, adjnode);
                            }
                        }
                    }
                }
            }
        }


        int dii[] = {+1,0,-1,0};
        int djj[] = {0,+1,0,-1};
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if(grid[row][col] == 0){
                    set<int> neighbourParent ;
                    for(int k = 0 ; k < 4 ; k++ ){
                        int nrow = row + dii[k];
                        int ncol  = col + djj[k];
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol< m && grid[nrow][ncol] == 1 ){
                            neighbourParent.insert(ds.findParent(nrow * m + ncol));
                        }
                    }
                    int temp = 1;
                    for(auto i : neighbourParent){
                        temp += ds.getSize(i);
                    }
                    ans = max(ans,temp);

                }
            }
        }
        if(ans == 0) {  
            for(int i = 0; i < n*m; i++) {
                ans = max(ans, ds.getSize(ds.findParent(i)));
            }
        }

        return ans;
    }
};