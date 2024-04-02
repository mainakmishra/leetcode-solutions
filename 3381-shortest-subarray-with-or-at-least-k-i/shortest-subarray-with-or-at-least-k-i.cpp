class Solution {
public:

    int minimumSubarrayLength(vector<int>& a, int k) {
        int right=0;
        int n=a.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=i;j<n;j++){
                x=x|a[j];
                if(x>=k){
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};