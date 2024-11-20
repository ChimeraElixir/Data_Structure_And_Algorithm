class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
                pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
                greater<pair<int,pair<int,int>>>
            > pq;

        // max diff , 
        pq.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int> (m,1e9));


        int di[] = {1,0,-1,0};
        int dj[] = {0,1,0,-1};

        while(!pq.empty()){
            int  effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return effort;

            for(int k=0 ;k< 4 ;k++){
                int nrow = row + di[k];
                int ncol = col + dj[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol< m ){

                    int newEffort = max(effort,abs(heights[row][col]-heights[nrow][ncol]));

                    if( newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};