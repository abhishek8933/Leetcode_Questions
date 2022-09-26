class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st;
        
        for(int i=0;i<arr.size();i++){
            int x=0;
            int j=i-1;
            int y=arr[i];
            st.insert(y);
            while(j>=0 && x!=y){
                x|=arr[j];
                y|=arr[j];
                st.insert(y);
                j--;
            }
        }
        return st.size();
        
    }
};