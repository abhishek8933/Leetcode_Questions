class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int high=nums.size()-1;
        if(nums.size()==1){
            return 0;
        }
        
        while(start<=high){
            int mid=start+(high-start)/2;
            if(mid>0 && mid<nums.size()-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                    start=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
               if(mid==0){
                   if(nums[mid]>nums[mid+1]){
                       return 0;
                   }else{
                       return 1;
                   }
               }else if(mid==nums.size()-1){
                   if(nums[mid]>nums[mid-1]){
                       return nums.size()-1;
                   }else{
                       return nums.size()-2;
                   }
               }
            }
        }
        return -1;
    }
};