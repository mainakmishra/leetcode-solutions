class Solution {
public:
    int coinChange(vector<int>& num, int x) {
        int dp[x+1];
        dp[0]=0;
        if(x==0)return 0;
        sort(num.begin(),num.end());
        for(int i=1;i<=x;i++){
            int m=1e9;
            for(auto &j:num){
                if(j<=i){
                    m=min(m,dp[i-j]);
                }
            }
            dp[i]=1+m;
        }
        if(dp[x]>=1e9)return -1;
        return dp[x];
        }
};