class Solution {
public:
    bool canPartition(vector<int>& nums,vector<int>& visited,int target,int curr_sum,int i,int k){
        if(k==1){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(curr_sum==target){
            return canPartition(nums,visited,target,0,0,k-1);
        }
        for(int j=i;j<nums.size();j++){
            if(visited[j]||curr_sum+nums[j]>target){
                continue;
            }
             visited[j]=true;
            if(canPartition(nums,visited,target,curr_sum+nums[j],j+1,k)){
                return true;
            }
            visited[j]=false;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        if(nums.size()<k||sum%k!=0){
            return false;
        }
        vector<int>visited(nums.size(), false);
        
        return canPartition(nums,visited,sum/k,0,0,k);
        
    }
};