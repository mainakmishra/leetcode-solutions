class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map <int,int> mp;
        for(auto &i:nums)++mp[i];
        int x=0;
        for(auto &i:mp){
            if(i.second==2)x=x^i.first;
        }
        return x;
    }
};