class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0,n=arr.size();
        for(auto &i:arr)sum+=i;
        if(sum & 1)return false;
        int target=sum/2;
        int dp[n+1][target+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i==0 and j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=0;
                else if(j==0)dp[i][j]=1;
                else{
                    if(dp[i-1][j]==1)dp[i][j]=1;
                    else if(j>=arr[i-1]){
                        dp[i][j]=dp[i-1][j-arr[i-1]];
                    }
                    else dp[i][j]=dp[i-1][j];
                    
                }
            }
        }
        return dp[n][target];
    }
};