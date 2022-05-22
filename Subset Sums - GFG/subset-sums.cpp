// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(vector<int> &arr,vector<int> &ans,int i,int sum,int n){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        helper(arr,ans,i+1,sum+arr[i],n);
        helper(arr,ans,i+1,sum,n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        // int sum=0;
        helper(arr,ans,0,0,N);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends