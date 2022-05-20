// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
       
       int m=1,k=0;
       vector<pair<int,int>> ans;
       for(int i=0;i<n;i++){
           ans.push_back(make_pair(end[i],start[i]));
       }
       sort(ans.begin(),ans.end());
       for(int i=0;i<n;i++){
           if(ans[k].first<ans[i].second){
               k=i;
               m++;
           }
       }
       return m;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends