class Solution {
public:
    vector<vector<int>>dist;
    
    int dijkstra(int n,vector<vector<int>>& grid){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        dist[0][0]=1;

        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int d=tp.first;
            int r=tp.second.first;
            int c=tp.second.second;
            if(d>dist[r][c])continue;
            vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
            if(r==n-1&&c==n-1)return dist[r][c];
            for(int i=0;i<8;i++){
                int nr=r+dirs[i][0];
                int nc=c+dirs[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<n&&grid[nr][nc]==0){
                    if(dist[nr][nc]>dist[r][c]+1){
                        dist[nr][nc]=dist[r][c]+1;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        dist.resize(n,vector<int>(n,1e5));
        return dijkstra(n,grid);
    }
};