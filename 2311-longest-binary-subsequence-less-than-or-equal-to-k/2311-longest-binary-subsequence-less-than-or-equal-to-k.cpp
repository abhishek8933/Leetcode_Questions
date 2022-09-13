class Solution {
public:
    int ans=0;
    int find(int i,int size,int sum,string &s,vector<vector<int>>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i][size]!=-1){
            return dp[i][size];
        }
        int not_include=find(i-1,size,sum,s,dp);
        int include=0;
        if((sum-(s[i]-'0')* pow(2,size))>=0){
            include=1+find(i-1,size+1,(sum-(s[i]-'0')* pow(2,size)),s,dp);
        }
        return dp[i][size]=max(include,not_include);
        
    }
    int longestSubsequence(string s, int k) {
       // unsigned long long int sum=0;
       //  int n=s.size();
       //  int i=n-1;
       //  int idx=0;
       //  string ans="";
       //  while(i>=0 && k>=0){
       //      k-=(pow(2,idx)*(s[i]-'0'));
       //      ans.push_back(s[i]);
       //        if(k<0){
       //          k+=(pow(2,idx)*(s[i]-'0'));
       //          ans.pop_back();
       //      }
       //      idx++;
       //      i--;
       //  }
       //  return ans.length();
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(n-1,0,k,s,dp);
       
    }
};