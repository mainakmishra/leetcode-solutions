class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        map <int,int> mp;
        int i,cnt=0,flag=0;
        for(i=0;i<n;i++){
            ++mp[nums[i]];
        }
        int ans=mp[1];
        if(ans%2==0 and ans!=0)ans-=1;
        for(auto &i:mp){
            long long x=pow(i.first,0.5);
            cnt=1;
            while(x>=2){
                if(mp.find(x)!=mp.end()){
                    if(mp[x]>=2)cnt+=2;
                    else break;
                    x=pow(x,0.5);
                }
                else break;
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};