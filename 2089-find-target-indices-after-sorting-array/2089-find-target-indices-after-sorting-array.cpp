class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
         int low=0;
        int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low-(low-high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        low=0;
        high=nums.size()-1;
        int second=-1;
        while(low<=high){
             int mid=low-(low-high)/2;
            if(nums[mid]==target){
                second=mid;
                low=mid+1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        for(int i=first;i<=second;i++){
            if(i==-1){
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};