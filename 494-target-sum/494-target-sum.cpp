class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int n=nums.size();
        long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum+target)%2!=0 ||target>sum){
            return 0;
        }
        int targt=(sum+target)/2;
        int t[n+1][targt+1];
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }
        for(int j=1;j<=targt;j++){
            t[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=targt;j++){
               if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
         return t[n][targt];
    }
};