class Solution {
public:
    int change(int x, vector<int>& num) {
        vector <int> dp(x+1,0);
        dp[0]=1;
        int n=num.size();
        //sort(num,num+n);
        for(int i=0;i<n;i++){
            for(int j=1;j<=x;j++){
                if(num[i]<=j){
                    dp[j]+=dp[j-num[i]];
                }
            }
        }
        return dp[x];
    }
};