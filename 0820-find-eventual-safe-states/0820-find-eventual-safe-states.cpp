class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adjRev(n);
        vector<int> inDegree(n,0);

        for(int i=0;i<n;i++){
            //i->j
            for(auto j: graph[i]){
                //j->i
                adjRev[j].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto adj:adjRev[node]){
                inDegree[adj]--;
                if(inDegree[adj]==0){
                    q.push(adj);
                }
            }

        }

        sort(ans.begin(),ans.end());

        return ans;


    }
};