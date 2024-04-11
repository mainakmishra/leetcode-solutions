class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1)return 0;
        int dp[n][m];
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                dp[i][j]=0;
                if(i-1>=0 and i-1<n and grid[i][j]==0)dp[i][j]+=dp[i-1][j];
                if(j-1>=0 and j-1<m and grid[i][j]==0)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};