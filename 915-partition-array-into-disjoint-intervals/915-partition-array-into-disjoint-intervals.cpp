class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxm=nums[0];
        int curr=nums[0];
        int ans=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<maxm){
                ans=i+1;
                maxm=curr;
            }else if(nums[i]>curr){
                curr=nums[i];
            }
        }
        return ans;
    }
};