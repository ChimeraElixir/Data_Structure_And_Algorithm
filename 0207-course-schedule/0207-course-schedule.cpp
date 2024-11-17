class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& adj) {
        int V = numCourses;
        map<int,vector<int>> m;
        vector<int> inDegree(V,0);
        vector<int> ans;
        queue<int> q;
        
        for( auto adjacent:adj){
            m[adjacent[1]].push_back(adjacent[0]);
            inDegree[adjacent[0]]++;
        }
        
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto adjacent:m[node]){
                inDegree[adjacent]--;
                if(!inDegree[adjacent]){
                    q.push(adjacent);
                }
                
            }
        }
        

        return ans.size()==V;
    }
};