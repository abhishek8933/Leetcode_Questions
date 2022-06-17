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
    int moves=0;
    void solve(TreeNode *root,TreeNode *Parent){
        if(root==NULL){
            return;
        }
        solve(root->left,root);
        solve(root->right,root);
        if(root->val>=1){
            int extra=root->val-1;
            Parent->val+=extra;
            root->val=1;
            moves+=extra;
            
        }else{
            int need=1+abs(root->val);
            Parent->val-=need;
            root->val=1;
            moves+=need;
        }
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        solve(root,root);
        return moves;
    }
};