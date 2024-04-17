/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    void smallest(TreeNode* root, string start, vector <string> &v){
        if(!root)return;
        start=start+(char)('a'+root->val);
        if(!root->left and !root->right){
            reverse(start.begin(),start.end());
            v.push_back(start);
        }
        smallest(root->left,start,v);
        smallest(root->right,start,v);

    }
    string smallestFromLeaf(TreeNode* root) {
        vector <string> v;
        smallest(root,"",v);
        sort(v.begin(),v.end());
        return v[0];
    }
};