class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        dp[0][0]=triangle[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i==0 and j==0)continue;
                int op1=1e9,op2=1e9;
                //[i-1][j] and [i-1][j-1]
                if(j<i and j>=0)op1=dp[i-1][j];
                if(j-1>=0)op2=dp[i-1][j-1];
                dp[i][j]=triangle[i][j]+min(op1,op2);
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};