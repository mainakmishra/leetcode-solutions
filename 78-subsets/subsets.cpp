class Solution {
    void f(int idx,vector<int>& nums,vector<int> &ans,vector<vector<int>> &print){
        if(idx==nums.size()){
            print.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        f(idx+1,nums,ans,print);
        ans.pop_back();
        f(idx+1,nums,ans,print);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<vector<int>> print;
        f(0,nums,ans,print);
        return print;
    }
};