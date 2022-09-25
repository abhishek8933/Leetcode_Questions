class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
          int n=nums.size();
        vector<int> dp1(n+1,1),dp2(n+1,1),ans;
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                dp1[i]=dp1[i-1]+1;
            }else{
                dp1[i]=0;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                dp2[i]=dp2[i+1]+1;
            }else{
                dp2[i]=0;
            }
        }
        for(int i=time;i<n-time;i++){
            if(dp1[i]>=time && dp2[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};