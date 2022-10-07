class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int i=0,j=0,sum=0;
        int res=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[i];
                    res=min(res,j-i+1);
                    i++;
                }
            }
            j++;
        }
        return res==INT_MAX?0:res;
    }
};