class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int abs_diff=abs(arr[1]-arr[0]);
        for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i+1]-arr[i])<abs_diff){
                abs_diff=abs(arr[i+1]-arr[i]);
            }
        }
        
        for(int i=0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i])==abs_diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};