class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false); std::cin.tie(nullptr);
    }
    int maxSubarrayLength(vector<int>& a, int k) {
        unordered_map <int,int> mp;
        int n=a.size();
        int left=0,ans=0;
        for(int i=0;i<n;i++){
            ++mp[a[i]];
            while(mp[a[i]]>k){
                --mp[a[left]];
                ++left;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};