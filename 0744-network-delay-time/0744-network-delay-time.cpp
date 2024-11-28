class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge : times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        //dist,from
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        while(!pq.empty()){
            int distance = pq.top().first;
            int from = pq.top().second;
            pq.pop();

            for(auto adjacent : adj[from]){
                int to = adjacent.first;
                int newTime = distance + adjacent.second;

                if(newTime < dist[to]){
                    dist[to] = newTime;
                    pq.push({newTime,to});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(dist[i]!=1e9){
                ans = max(ans,dist[i]);
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};