class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<bool>xors(2048,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xors[(nums[i]^nums[j])]=true;
            }
        }

        int ans=0;
        vector<bool>xorss(2048,false);
        for(int i=0;i<2048;i++){
            if(xors[i]==false) continue;
            for(int j=0;j<n;j++){
                int temp=(nums[j]^i);
                if(xorss[temp]==false){
                    xorss[temp]=true;
                    ans++;
                }
            }
        }
        return ans;
    }
};