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
   bool isbst(TreeNode* root,long max,long min){
    if(!root) return true;
    if(root->val>=max || root->val<=min) return false;
    return isbst(root->left,root->val,min) && isbst(root->right,max,root->val);
   }
public:
    bool isValidBST(TreeNode* root) {
        long long int min=LLONG_MIN, max = LLONG_MAX;
        return isbst(root,max,min);
    }
};