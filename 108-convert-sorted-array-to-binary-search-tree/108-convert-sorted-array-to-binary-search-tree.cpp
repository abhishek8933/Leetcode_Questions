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
    TreeNode * solve(vector<int>& nums,int i,int j){
        if(i>=j){
            return NULL;
        }
        int mid=i-(i-j)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=solve(nums,i,mid);
        root->right=solve(nums,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return solve(nums,0,nums.size());
    }
};