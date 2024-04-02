class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int left=0;
        int ans=0,current=0,count=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)current++;
            while(current>k and left<n){
                if(a[left]==0)--current;
                ++left;
            }
            ans=max(ans,i-left+1);
        }
        return ans;

    }
};