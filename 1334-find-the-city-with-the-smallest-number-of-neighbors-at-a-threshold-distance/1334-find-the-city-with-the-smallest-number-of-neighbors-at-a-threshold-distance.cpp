class Solution {
public:
    vector<int>ans;
    vector<vector<pair<int, int>>>adj;
   
    void dijkstra(int src,int n,int k){
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        int ct=-1;
        dist[src]=0;

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if(d>dist[u])continue;

            for(auto v:adj[u]){
                int node=v.first;
                int w=v.second;
                if(dist[node]>dist[u]+w){
                    dist[node]=dist[u]+w;
                    pq.push({dist[node],node});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]<=k)ct++;
        }
        ans.push_back(ct);
    }

    int findTheCity(int n, vector<vector<int>>& edges, int di) {
        adj.assign(n,vector<pair<int,int>>());
        ans.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int num=-1,cnt=1e9;
        for(int i=0;i<n;i++){
            dijkstra(i,n,di);
            if(ans[i]<=cnt){
                cnt=ans[i];
                num=i;
            }
        }
        return num;
    }
};