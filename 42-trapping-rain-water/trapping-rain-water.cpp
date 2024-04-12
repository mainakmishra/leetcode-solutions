class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,leftmax=0,rightmax=0;
        int ans=0;
        while(left<right){
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            if(leftmax<rightmax){
                ans+=leftmax-height[left];
                ++left;
            }
            else{
                ans+=rightmax-height[right];
                --right;
            }
        }
        return ans;
    }
};