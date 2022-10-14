//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void construct(vector<int>&nums,int low,int high,vector<int>&ans){
        if(low>high){
            return;
        }
        int mid=low-(low-high)/2;
        ans.push_back(nums[mid]);
        construct(nums,low,mid-1,ans);
        construct(nums,mid+1,high,ans);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>  ans;
        construct(nums,0,nums.size()-1,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends