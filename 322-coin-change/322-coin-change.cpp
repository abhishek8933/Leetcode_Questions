class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int w=amount;
        int arr[n+1][w+1];
        for(int i=0;i<=n;i++){
            arr[i][0]=0;
        }
        for(int i=0;i<=w;i++){
            arr[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(coins[i-1]>j){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=min(arr[i-1][j],1+arr[i][j-coins[i-1]]);
                }
            }
        }
        if(arr[n][w]>=INT_MAX-1){
            return -1;
        }
        return arr[n][w];
    
    }
};