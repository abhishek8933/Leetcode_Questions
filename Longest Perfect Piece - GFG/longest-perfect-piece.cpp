//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min;
        priority_queue<pair<int ,int>> Max;
        int ans=0,left=0,right=0;
        while(right<n){
            Min.push({arr[right],right});
            Max.push({arr[right],right});
            
            while(left<right && Max.top().first-Min.top().first>1){
                left++;
                while(Max.top().second<left){
                    Max.pop();
                }
                while(Min.top().second<left){
                    Min.pop();
                }
            }
            ans=max(ans,right-left+1);
            right++;
        }
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
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends