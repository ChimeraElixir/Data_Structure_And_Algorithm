#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> distance(vertices,INT_MAX);

    priority_queue<pair<int,int>> sp;  

    distance[source]=0;

    sp.push(make_pair(0,source));

    while(!sp.empty()){

        auto top=sp.top();

        int nodedist=top.first;
        int topNode=top.second;

        sp.pop();

        for(auto neighbour:adj[topNode]){
            if(nodedist+neighbour.second<distance[neighbour.first]){
                
                distance[neighbour.first]=nodedist+neighbour.second;
                sp.push(make_pair(nodedist+neighbour.second,neighbour.first));
            }
        }
    }



    return distance;
}
// Driver Code Starts