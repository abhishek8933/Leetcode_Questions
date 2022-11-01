//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {
           const int mod=1e9+7;
          vector<long long> c(n+1,0);
        
        c[0]=1;
        c[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                c[i]=(c[i]+ (c[j]*c[i-1-j])%mod)%mod;
            }
        }
        return c[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends