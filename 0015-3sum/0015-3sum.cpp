class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
    
        vector<vector<int>>ans;
        for(int k=0;k<n;k++){
            if(k!=0){
                while(k<n && nums[k]==nums[k-1])k++;
                if(k==n)return ans;
            }
            int i=k+1,j=n-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[k],nums[i],nums[j]});
                    i++;
                    while(i<j && nums[i]==nums[i-1])i++;
                    j--;
                    while(i<j && nums[j]==nums[j+1])j--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)i++;
                else j--;
            }
        }
        // vector<vector<int>>vec;
        // for(auto it:ans)vec.push_back(it);
        return ans;
        
    }
};