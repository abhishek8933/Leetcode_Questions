class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> original=nums;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        vector<int> ans;
        int n=nums.size();
      for(int index = 0 ; index < k ; index ++) map[nums[nums.size() - 1- index]]++; 
    
        for(auto it:original){
            if(map[it]-->0){
                ans.push_back(it);
            }
        }
        return ans;
        
        
    }
};