class Solution {
public:
    static bool cmp(int a, int b){
        string c = to_string(a);
        string d = to_string(b);
        return c+d>d+c;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0)return "0";
        for(auto &i : nums)ans += to_string(i);
        return ans;
    }
};