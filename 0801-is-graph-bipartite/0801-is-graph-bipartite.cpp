class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V,-1);
	    queue <pair<int,int>>  q;
	    
	    for(int i=0;i<V;i++){
	        if(visited[i]==-1){
	            
	            q.push({i,0});
	            visited[i] = 0;
	            
	            while(!q.empty()){
	              int curr = q.front().first;
	              int color = q.front().second;
	              q.pop();
	              visited[curr] = color;
	              
	              for(auto adjacent:adj[curr]){
	                  if(visited[adjacent]==-1){
	                      q.push({adjacent,!color});
	                  }
	                  else if(visited[adjacent]==color){
	                      return false;
	                  }
	              }
	            }
	        }
	    }
	    return true;
    }
};