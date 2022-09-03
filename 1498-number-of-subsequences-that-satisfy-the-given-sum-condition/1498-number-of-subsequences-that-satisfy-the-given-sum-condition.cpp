class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1000000007;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        vector<int>pow2(nums.size()+1,1);
        for(int i=1;i<=nums.size();i++)
        {
            pow2[i]=(2*pow2[i-1])%mod;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=(ans+pow2[j-i])%mod;
                i++;
            }else{
                j--;
            }
        }
        return ans;
        
    }
};