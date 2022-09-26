class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n/2;i++){
            if(nums[i]+nums[n-1-i]>ans){
                ans=nums[i]+nums[n-1-i];
            }
        }
        return ans;
    }
};