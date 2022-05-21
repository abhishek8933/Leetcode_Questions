// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=1,j=0;
        int plat=1;
        while(i<n&&j<n){
            if(dep[j]>=arr[i]){
                plat++;
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        return plat;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends