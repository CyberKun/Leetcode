class Solution {
public:

    vector<vector<long long>>dist;
    vector<vector<pair<int,int>>>adj;

    int dijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;

        pq.push({0,{src,0}});
        dist[src][0]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int d=temp.first;
            int curr=temp.second.first;
            int stps=temp.second.second;

            if(curr==dst)return dist[curr][stps];
            if(d>dist[curr][stps]||stps==k+1)continue;

            for(auto v:adj[curr]){
                if(dist[v.first][stps+1]>dist[curr][stps]+v.second){
                    dist[v.first][stps+1]=dist[curr][stps]+v.second;
                    pq.push({dist[v.first][stps+1],{v.first,stps+1}});
                }
            } 
        }
        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dist.assign(n,vector<long long>(k+2,1e18));
        adj.assign(n+1,vector<pair<int,int>>());
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        return dijkstra(n,flights,src,dst,k);
    }
};