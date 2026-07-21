class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)pq.push({arr[i],i});

        vector<int>ans(n);
        int rank=1;
        int pval=pq.top().first; 
        while(!pq.empty()){
            auto [val,i]=pq.top();
            pq.pop();
            if (val>pval){
                rank++;
                pval=val;
            }
            ans[i]=rank; 
        }

        return ans;
    }
};