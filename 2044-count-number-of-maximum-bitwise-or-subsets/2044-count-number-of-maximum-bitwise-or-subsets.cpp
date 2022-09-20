class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int num_of_sub=pow(2,nums.size());
        int maxm_or=0;
        for(int i=0;i<nums.size();i++){
            maxm_or|=nums[i];
        }
        int ans=0;
        for(int i=0;i<num_of_sub;i++){
            int orr=0;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    orr|=nums[j];
                }
            }
            if(orr==maxm_or){
                ans++;
            }
        }
        return ans;
    }
};