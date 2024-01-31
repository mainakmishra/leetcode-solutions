class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(auto &i:nums)++mp[i];
        int missing=1;
        while(1){
            if(mp[missing]==0){
                return missing;
            }
            else ++missing;
        }
    }
};