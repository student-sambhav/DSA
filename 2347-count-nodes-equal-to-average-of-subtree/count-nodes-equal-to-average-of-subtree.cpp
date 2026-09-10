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
int getsub(TreeNode* root,int &cnt,int &nodes){
    if(root==NULL){
        nodes=0;
        return 0;
    }
    int lnodes=0,rnodes=0;
    int lsum=getsub(root->left,cnt,lnodes);
    int rsum=getsub(root->right,cnt,rnodes);
    int sum=lsum+rsum+root->val;
    nodes=lnodes+rnodes+1;
    if(sum/nodes==root->val){
        cnt++;
    }
    return sum;


}
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        int nodes=0;
        getsub(root,cnt,nodes);
        return cnt;
    }
};