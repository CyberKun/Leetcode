#include<vector>
#include<queue>
using namespace std;
class Solution{
public:
    vector<int> remainingMethods(int n,int k,vector<vector<int>>&invocations){
        vector<vector<int>>g(n);
        for(auto i:invocations){
            g[i[0]].push_back(i[1]);
        }
        vector<bool>s(n,false);
        queue<int>q;
        q.push(k);
        s[k]=true;
        while(!q.empty()){
            int c=q.front();
            q.pop();
            for(int i:g[c]){
                if(!s[i]){
                    s[i]=true;
                    q.push(i);
                }
            }
        }
        bool ok=true;
        for(auto i:invocations){
            if(!s[i[0]]&&s[i[1]]){
                ok=false;
                break;
            }
        }
        vector<int>ans;
        if(ok){
            for(int i=0;i<n;++i){
                if(!s[i]){
                    ans.push_back(i);
                }
            }
        }else{
            for(int i=0;i<n;++i){
                ans.push_back(i);
            }
        }
        return ans;
    }
};