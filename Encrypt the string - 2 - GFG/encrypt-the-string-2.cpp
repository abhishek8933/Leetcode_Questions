//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string encryptString(string S) {
      string ans="";
       int count=1,i=0;
       for( i=0;i<S.size();i++){
           if(S[i]==S[i+1]){
               count++;
           }
           else{
               ans.push_back(S[i]);
               int temp=count;
               int r;
               while (temp != 0)
               {
                   r = temp % 16;
                   if (r < 10)
                       ans.push_back(r+48);
                   else
                       ans.push_back(r+87);
                   temp = temp / 16;
                   count=1;
               }
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
   }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends