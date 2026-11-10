class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct=1;
        int n=nums.size();
        set<int>st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])ct++;
            st.insert(nums[i]);
        }

        int i=0;
        for(auto it:st){
            nums[i]=it;
            it++;
            i++;
        }
        return ct;
    }
};