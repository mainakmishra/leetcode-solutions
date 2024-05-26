
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long count=0;
        map <long long,long long> mp;
        for(auto &i:nums1)++mp[i];
        for(long long i=0;i<nums2.size();i++)nums2[i]*=k;
        long long m=*max_element(nums1.begin(),nums1.end()); 
        for(long long i=0;i<nums2.size();i++){
            if(nums2[i]==1){
                count+=nums1.size();
                continue;
            }
            else if(nums2[i]>m)continue;
            for(long long j=1;j<=m/nums2[i];j++){
                count+=mp[j*nums2[i]];
            }
        }
        return count;
    }
};