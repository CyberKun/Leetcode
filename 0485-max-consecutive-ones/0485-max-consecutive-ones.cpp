class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mxct=0,ct=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==1)ct++;
            else ct=0;
            mxct=max(mxct,ct);
        }
        return mxct;
        
    }
};