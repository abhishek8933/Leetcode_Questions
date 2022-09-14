class Solution {
public:
    int t[17][17];
     vector<vector<string>> ans;
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
    void solve(string s,int i,int j,vector<string>& temp){
        if(i==j){
            ans.push_back(temp);
            return;
        }
        for(int k=i;k<j;k++){
           if(isPalindrome(s,i,k)){
               temp.push_back(s.substr(i,k-i+1));
                solve(s,k+1,j,temp);
                temp.pop_back();
           }
        }
        
    }
    vector<vector<string>> partition(string s) {
        memset(t,-1,sizeof(t));
        vector<string> temp;
        solve(s,0,s.size(),temp);
        return  ans;
    }
};