class Solution {
public:
    int uniquePaths(int n, int m) {
        int dp[n][m];
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                dp[i][j]=0;
                if(i-1>=0 and i-1<n)dp[i][j]+=dp[i-1][j];
                if(j-1>=0 and j-1<m)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};