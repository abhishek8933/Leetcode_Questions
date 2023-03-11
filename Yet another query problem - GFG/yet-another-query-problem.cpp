//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int nums, vector<int> &num, vector<vector<int>> &Q) {
        
          vector<int>res,precomputed_freq;
        for(int i=0;i<N;i++){
            int freq=1;
            int ele=num[i];
            for(int j=i+1;j<N;j++){
                if(num[j]==num[i]){
                    freq++;
                }
            }
            precomputed_freq.push_back(freq);
        }
        for(int i=0;i<nums;i++){
            int l=Q[i][0];
            int h=Q[i][1];
            int frequency=Q[i][2];
            int number=0;
            for(int j=l;j<=h;j++){
                if(precomputed_freq[j]==frequency){
                    number++;
                }
            }
            res.push_back(number);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends