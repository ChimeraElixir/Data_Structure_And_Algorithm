class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        // Code here
	    vector<int> inDegree(N,0);
	    vector<vector<int>> adj(N);
	    queue<int> q;
	    vector<int> ans;
	    
	    for(auto i:prerequisites){
	        inDegree[i[0]]++;
	        adj[i[1]].push_back(i[0]);
	    }
	    
	    for (int i=0;i<N;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto adjacent:adj[node]){
	            inDegree[adjacent]--;
	            if(inDegree[adjacent]==0){
	                q.push(adjacent);
	            }
	            
	        }
	    }
	    
        if(ans.size()==N){
            return ans;
        }
	    return {};
    }
};