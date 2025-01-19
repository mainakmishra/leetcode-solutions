class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // To store the prefix sums
        
        // Compute the prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long totalSum = 0;
        
        // Iterate over each index and compute the sum of the subarray
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            totalSum += prefix[i + 1] - prefix[start];
        }
        
        return totalSum;
    }
};
