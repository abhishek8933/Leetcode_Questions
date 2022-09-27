class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(st.count(nums2[i])){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }
};