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
     vector<vector<int>> final_ans;
    void solve(TreeNode *root,int target,vector<int> &temp){
       if(root==NULL){
           return;
       }
        if(!root->left and !root->right and target == root->val){
            temp.push_back(root->val);
            final_ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        solve(root->left,target-root->val,temp);
        solve(root->right,target-root->val,temp);
        temp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        // int ans=targetSum;
        solve(root,targetSum,temp);
        return final_ans;
    }
};