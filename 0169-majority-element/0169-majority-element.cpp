class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],fq=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==ans)fq++;
            else if(fq==0){
                ans=nums[i];
                fq=1;
            }
            else fq--;
        }
        return ans;
    }
};