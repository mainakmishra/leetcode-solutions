class Solution {
public:
    int findMin(vector<int>& a){
        int n=a.size();
        int left=0,right=n-1,ans=0,mid=0;
        while(left<=right){
            mid=(left+right)/2;
            if(a[mid]>a[n-1])++left;
            else{
                ans=a[mid];
                --right;
            }
        }
        return ans;
    }
};