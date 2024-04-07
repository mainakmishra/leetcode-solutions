class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int inc=1,dec=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[j-1])inc++;
                else break;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[j-1])dec++;
                else break;
            }
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};