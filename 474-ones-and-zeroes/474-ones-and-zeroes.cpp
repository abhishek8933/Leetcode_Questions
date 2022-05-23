class Solution {
public:
    void count(string &a,int &zeroes,int &ones){
        zeroes=ones=0;
        for(auto i:a){
            if(i=='1'){
                ones++;
            }else{
                zeroes++;
            }
        }
    }
    int solve(int i,vector<string>&strs,int m,int n,int zeroes,int ones,vector<vector<vector<int>>>&dp){
        if(i==strs.size()||m+n==0){
            return 0;
        }
        if(dp[i][m][n] != -1)
				return dp[i][m][n];
        count(strs[i],zeroes,ones);
        //include
        int consider=0;
        if(m>=zeroes && n>=ones){
            consider=1+solve(i+1,strs,m-zeroes,n-ones,zeroes,ones,dp);
        }
        //exclude
        int skip=solve(i+1,strs,m,n,zeroes,ones,dp);
        // return max(consider,skip);
     return   dp[i][m][n]=max(skip,consider);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
		int size = strs.size();
		vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0,strs,m,n,0,0,dp);
    }
};