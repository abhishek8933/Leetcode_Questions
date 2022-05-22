class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int>& candidates,int target,vector<int>& temp,int i){
        if(target==0){
            ans.insert(temp);
            return;
        }
        if(target<0){
            return;
        }
        if(i==candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],temp,i+1);
        temp.pop_back();
        while(i+1<candidates.size()&&candidates[i+1]==candidates[i]){
            i++;
        }
        solve(candidates,target,temp,i+1);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<int> temp;
        solve(candidates,target,temp,0);
        vector<vector<int>> ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};