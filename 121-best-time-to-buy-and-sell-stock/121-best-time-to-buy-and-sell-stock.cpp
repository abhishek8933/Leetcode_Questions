class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int temp=0;
        for(int i=1;i<n;i++){
            temp=max(0,temp+=prices[i]-prices[i-1]);
            ans=max(ans,temp);
        }
        return ans;
    }
};