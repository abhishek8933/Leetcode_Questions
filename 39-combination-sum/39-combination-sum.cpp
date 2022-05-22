class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates,vector<int> temp,int target,int i,int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
         if(target<0){
            return;
        }
        if(i==n){
            return;
        }
        //exclude
        helper(candidates,temp,target,i+1,n);
        //include
        temp.push_back(candidates[i]);
        helper(candidates,temp,target-candidates[i],i,n);
        // temp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates,temp,target,0,candidates.size());
        return ans;
    }
};