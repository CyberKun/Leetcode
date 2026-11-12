class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>srtd=nums;
        sort(srtd.begin(),srtd.end());
        while(i<j){
            if(srtd[i]+srtd[j]==target){
                int a=-1,b=-1;
                for(int k=0;k<n;k++){
                    if(nums[k]==srtd[i] && a==-1)a=k;
                    if(nums[k]==srtd[j] && k!=a)b=k;
                }
                return {a,b};
            }
            if(srtd[i]+srtd[j]<target)i++;
            else j--;
        }
        return {0,0};
    }
};