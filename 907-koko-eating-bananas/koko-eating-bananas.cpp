class Solution {
    private:
    int check(vector<int> &piles, int mid, int h){
        long long count=0;
        for(auto &i:piles){
            count+=(i+mid-1)/mid;
        }
        return count<=h?1:0;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=1,right=1e9,mid;
        int ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(check(piles,mid,h) == true){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};