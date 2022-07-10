class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001]={0};
        int size=cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<size;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[size-1],dp[size-2]);
    }
};