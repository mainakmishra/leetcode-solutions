class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int N = nums.size();
        string ans = "";
        for(int i = 0; i < N; i++){
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};
