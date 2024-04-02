class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    long long countAlternatingSubarrays(vector<int>& a) {
        long long right=0,ans=0;
        long long n=a.size();
        long long flag=1;
        for(long long i=1;i<n;i++){
            if(a[i]==a[i-1]){
                flag=0;
                break;
            }
        }
        if(flag==1)return 1LL*n*(n+1)/2;
        for(long long i=0;i<n;i++){
            right=i;
            while(right<n-1 and a[right]!=a[right+1])right++;
            ans+=right-i+1;
        }
        return ans;
    }
};