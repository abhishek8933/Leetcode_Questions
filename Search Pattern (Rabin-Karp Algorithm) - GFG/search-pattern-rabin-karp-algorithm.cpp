//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int i=0,j=0;
            vector<int> ans;
            while(j<txt.size()){
                if(j-i+1<pat.size()){
                    j++;
                }
                if(j-i+1==pat.size()){
                    string temp=txt.substr(i,j-i+1);
                    if(temp==pat){
                        ans.push_back(i+1);
                    }
                    i++;
                    j++;
                }
            }
            if(ans.size()==0){
                return {-1};
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends