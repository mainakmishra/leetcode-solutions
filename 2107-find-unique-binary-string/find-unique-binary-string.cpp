
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end());
        return generateBinaryStrings("", numSet, n);
    }

private:
    string generateBinaryStrings(string current, unordered_set<string>& numSet, int n) {
        if (current.length() == n) {
            if (numSet.find(current) == numSet.end()) {
                return current;
            }
            return "";
        }

        for (char c : {'0', '1'}) {
            string binaryString = generateBinaryStrings(current + c, numSet, n);
            if (!binaryString.empty()) {
                return binaryString;
            }
        }
        return "";
    }
};
