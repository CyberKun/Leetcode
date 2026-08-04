class Solution {
public:
    vector<long long>dist;
    vector<vector<pair<int,int>>>adj;

    void dijkstra(int n, int k){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u])continue;
            
            for(auto v:adj[u]){
                if(dist[v.first]>dist[u]+v.second){
                    dist[v.first]=dist[u]+v.second;
                    pq.push({dist[v.first],v.first});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.assign(n+1,1e18);
        adj.assign(n+1,vector<pair<int,int>>());
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dijkstra(n,k);
        long long ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
        if(ans==1e18)return -1;
        return ans;

    }
};