class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,ans=0;
        long long pro=1;
        if(k<=1)return 0;
        for(int i=0;i<n;i++){
            pro*=nums[i];
            while(pro>=k){
                pro/=nums[left];
                left++;
            }
            ans+=1+i-left;
        }
        //for(auto &i:nums)if(i<k)++ans;
        return ans;
    }
};