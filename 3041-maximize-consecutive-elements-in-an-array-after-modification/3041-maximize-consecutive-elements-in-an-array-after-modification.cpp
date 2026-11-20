class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<n;i++){
            mp[nums[i]+1]=mp[nums[i]]+1;
            mp[nums[i]]=mp[nums[i]-1]+1;
            ans=max({ans,mp[nums[i]],mp[nums[i]+1]});
        }
        return ans;
    }
};