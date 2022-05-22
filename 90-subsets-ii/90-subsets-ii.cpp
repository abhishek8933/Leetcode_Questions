class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void helper(vector<int>& nums,vector<int>& temp,int i,int n){
        if(i==n){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(nums,temp,i+1,n);
        temp.pop_back();
        helper(nums,temp,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        helper(nums,temp,0,nums.size());
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};