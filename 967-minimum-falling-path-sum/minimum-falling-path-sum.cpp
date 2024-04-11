class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int dp[n][m];
        for(int i=0;i<m;i++)dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int op1=1e9,op2=1e9,op3=1e9;
                if(j-1>=0)op1=dp[i-1][j-1];
                op2=dp[i-1][j];
                if(j+1<m)op3=dp[i-1][j+1];
                dp[i][j]=matrix[i][j] + min(op1,min(op3,op2));
            }
        }
        int ans=1e9;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};