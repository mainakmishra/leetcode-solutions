class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<n;i++){
            int x=1e9;
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i)x=min(x,dp[j]+1);
            }
            dp[i]=x;
        }
        return dp[n-1];
    }
};