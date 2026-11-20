class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        map<int,int>mp;
        sort(nums.begin(),nums.end());
        //dp[0][0]=dp[0][1]=1;
        int ans=1;
        for(int i=0;i<n;i++){
            // if(nums[i]==nums[i-1]){
            //     dp[i][0]=1;
            //     dp[i][1]=dp[i-1][0]+1;
            // }
            // if(nums[i]==nums[i-1]+1){
            //     dp[i][0]=dp[i-1][0]+1;
            //     dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
            // }
            // if(nums[i]==nums[i-1]+2){
            //     dp[i][0]=1;
            //     dp[i][1]=dp[i-1][0]+1;
            // }
            // ans=max({ans,dp[i][0],dp[i][1]});
            mp[nums[i]+1]=mp[nums[i]]+1;
            mp[nums[i]]=mp[nums[i]-1]+1;
            ans=max({ans,mp[nums[i]],mp[nums[i]+1]});
        }
        return ans;
    }
};