//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
          long long int count=0;
        long long int ans=0;
        int mini=INT_MAX;
      for(int i=0;i<n;i++)
      {
          count+=(long long)(b[i]/2);
          ans+=(long long )a[i]*(b[i]-b[i]%2);
          if(b[i]>=2)
          mini=min(a[i],mini);
      }
      if(count%2!=0)
      ans-=mini*2;
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends