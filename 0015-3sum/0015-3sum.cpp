class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
    
        set<vector<int>>ans;
        for(int k=0;k<n;k++){
            int i=k+1,j=n-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    i++;
                    j--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)i++;
                else j--;
            }
        }
        vector<vector<int>>vec;
        for(auto it:ans)vec.push_back(it);
        return vec;
        
    }
};