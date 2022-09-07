class Solution {
public:
    int t[1001][1001];
    int solve(string &s1,int n1,string &s2,int n2){
        if(n1==0||n2==0){
            return 0;
        }
        if(t[n1][n2]!=-1){
            return t[n1][n2];
        }
        if(s1[n1-1]==s2[n2-1]){
            return t[n1][n2]=1+solve(s1,n1-1,s2,n2-1);
        }else{
            return t[n1][n2]=max(solve(s1,n1-1,s2,n2),solve(s1,n1,s2,n2-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(text1,text1.size(),text2,text2.size());
    }
};