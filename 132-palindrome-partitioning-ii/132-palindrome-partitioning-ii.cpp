class Solution {
public:
    int t[2001][2001];
     bool isPalindrome(string &s,int i,int j){
        while(j>i){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j){
        if(i>=j){
            return t[i][j]=0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
         if(isPalindrome(s,i,j)){
            return t[i][j]=0;
        }
        int ans=INT_MAX ;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)==false){
                continue;
            }
            int temp=(solve(s,i,k)+solve(s,k+1,j))+1;
            ans=min(ans,temp);
            t[i][j]=ans;
        }
        return ans;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
         return solve(s,0,s.size()-1);
    }
};