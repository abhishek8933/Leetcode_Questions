class Solution {
public:
    string longestPalindrome(string m) {
        string s=m;
        string b=string(s.rbegin(),s.rend());
        string res;
        int n=s.size();
        int t[n+1][n+1];
        int maxm=0;
        for(int i=0;i<=n;i++){
            t[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            t[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    if(t[i][j]>maxm){
                        string temp=m.substr(i-t[i][j],t[i][j]);
                        string temp1=string(temp.rbegin(),temp.rend());
                        if(temp==temp1){
                            maxm=t[i][j];
                            res=temp;
                        }
                    }
                }
                else{
                    t[i][j]=0;
                }
            }
        }
       
        return res;
    }
};