class Solution {
public:

    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int left=0;
        int ans=0,current=0,count=0;
        for(auto &i:a)if(i)++count;
        if(k==0 and count==0)return 0;
        for(int i=0;i<n;i++){
            if(a[i]==0)current++;
            while(current>k and left<n-1){
                if(a[left]==0)--current;
                ++left;
            }
            ans=max(ans,i-left+1);
        }
        return ans;

    }
};