class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int i=n;
        int j=m;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }else{
                if(t[i][j-1]>t[i-1][j]){
                    ans+=str2[j-1];
                    j--;
                }else{
                    ans+=str1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
         while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};