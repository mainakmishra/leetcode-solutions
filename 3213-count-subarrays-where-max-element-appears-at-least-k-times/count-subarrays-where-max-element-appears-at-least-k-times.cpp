class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    long long countSubarrays(vector<int>& a, int k) {
        long long ans=0;
        int n=a.size();
        unordered_map <int,int> mp;
        int right=-1;
        int m=*max_element(a.begin(),a.end());
        for(int i=0;i<n;i++){
            while(mp[m]<k and right<n){
                ++right;
                if(right<n)++mp[a[right]];
            }
            if(mp[m]>=k)ans+=n-right;
            --mp[a[i]];
        }
        return ans;
    }
};