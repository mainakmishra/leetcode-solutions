class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map <int,long long> mp;
        for(int i=0;i<nums.size();i++){
            ++mp[nums[i]-i];
        }
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums.size()-mp[nums[i]-i];
        }
        return count/2;
    }
};