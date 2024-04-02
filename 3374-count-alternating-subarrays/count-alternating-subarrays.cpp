class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    long long countAlternatingSubarrays(vector<int>& a) {
        long long right=0,ans=0;
        long long n=a.size();
        for(long long i=0;i<n;i++){
            right=max(i,right);
            while(right<n-1 and a[right]!=a[right+1])right++;
            ans+=right-i+1;
        }
        return ans;
    }
};