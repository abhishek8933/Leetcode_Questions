class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int n=abs(nums[i]);
            if(nums[n-1]>0){
                nums[n-1]=-nums[n-1];
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};