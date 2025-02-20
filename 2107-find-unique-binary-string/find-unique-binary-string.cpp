class Solution {
public:
    int N;
    string ans="";

    void f(string s, set<string> &st) {
        if (!ans.empty()) return; 
        if (s.length() == N) {
            if (st.find(s) == st.end()) {
                ans = s;
            }
            return;
        }
        f(s + '0', st);
        f(s + '1', st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        N = nums[0].length();
        set<string> st(nums.begin(), nums.end());
        f("", st);
        return ans;
    }
};
