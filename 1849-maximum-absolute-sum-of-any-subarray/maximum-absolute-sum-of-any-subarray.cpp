class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        int maxsum = 0, minsum = 0;

        for(int i=0; i<nums.size(); i++){
            sum1 = max(sum1+nums[i], nums[i]);
            sum2 = min(sum2+nums[i], nums[i]);

            maxsum = max(maxsum, sum1);
            minsum = min(minsum, sum2);
        }

        return max(abs(maxsum),abs(minsum));
    }
};