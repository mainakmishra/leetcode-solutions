class Solution {
public:
    int calc(vector <int> &bits){
        int sum=0;
        for(int i=0;i<32;i++){
            if(bits[i])sum+=(1<<i);
        }
        return sum;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int m=*max_element(nums.begin(),nums.end());
        if(m>=k)return 1;
        int n=nums.size();
        int right=0;
        vector <int> bits(32,0);
        int x=0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(i>0){
                for(int j=0;j<32;j++){
                    if((1<<j) & nums[i-1])--bits[j];
                }
            }
            x=calc(bits);
            while(right<n and x<k){
                x=x|nums[right];
                for(int j=0;j<32;j++){
                    if((1<<j) & nums[right])++bits[j];
                }
                ++right;
            }
            if(x>=k)ans=min(ans,right-i);
        }
        if(ans==1e9)return -1;
        return ans;

    }
};