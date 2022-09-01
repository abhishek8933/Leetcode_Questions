class Solution {
public:
    bool subset(vector<int> nums,int sum,int n){
        bool t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            t[i][0]=true;
        }
        for(int j=1;j<=sum;j++){
            t[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }else{
            int n=nums.size();
            return subset(nums,sum/2,n);
        }
    }
};