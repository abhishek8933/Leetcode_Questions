class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&nums,int i,int j){
        if(i>=j){
            ans.push_back(nums);
            return;
        }
        for(int k=i;k<j;k++){
            swap(nums[i],nums[k]);
            solve(nums,i+1,j);
            swap(nums[i],nums[k]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,nums.size());
        return ans;
    }
};