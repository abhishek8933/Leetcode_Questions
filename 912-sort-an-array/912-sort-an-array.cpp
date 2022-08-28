class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int h){
        int i=l;
        int j=mid+1;
        int k=l;
        int array[h+1];
        while(i<=mid && j<=h){
            if(nums[i]<nums[j]){
                array[k++]=nums[i++];
            }else{
                array[k++]=nums[j++];
            }
        }
        while(i<=mid){
            array[k++]=nums[i++];
        }
         while(j<=h){
            array[k++]=nums[j++];
        }
        for(int i=l;i<=h;i++){
            nums[i]=array[i];
        }
    }
    void sort(vector<int>&nums,int l,int h){
        if(l<h){
            int mid=l+(h-l)/2;
            sort(nums,l,mid);
            sort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size()-1);
        return nums;
    }
};