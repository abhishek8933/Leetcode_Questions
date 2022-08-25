class Solution {
public:
    bool isValid(vector<int>& nums,int k,int mid){
        int sum=0;
        int sub=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                sub++;
                sum=nums[i];
            }
            if(sub>k){
                return false;
            }
        }
        return true;
        // int sum=0,count=1;
        // for(int i=0;i<n.size();i++){
        //     sum+=n[i];
        //     if(sum>mid){
        //         sum=n[i];
        //         count++;
        //     }
        //     if(count>m)return 0;
        // }
        // return 1;
    }
    int splitArray(vector<int>& nums, int m) {
        // sort(nums.begin(),nums.end());
        int start=INT_MIN;
        // int start=nums[nums.size()-1;
        int end=0;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            end+=nums[i];
            if(nums[i]>start){
                start=nums[i];
            }
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(nums,m,mid)){
                end=mid-1;
                 res=mid;
            }else{
                start=mid+1;
            }
        }
        return res;
    }
};