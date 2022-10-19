//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int find(int a,int b){
      while(a!=b){
          if(a>b){
              a=a-b;
          }else{
              b=b-a;
          }
      }
      return a;
  }
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        sort(arr.begin(),arr.end());
        int ans=0;
        if(arr.size()<=1){
            return 0;
        }
        for(int i=0;i<arr.size()-1;i=i+2){
           
           if(arr[i][0]!=arr[i+1][0]){
               i--;
               continue;
           }
           int l=arr[i][1];
           int r=arr[i+1][1];
           ans=max(ans,find(l,r));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends