class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        vector<long long int> temp(n,0);
        temp[0]=nums[0];
        for(int i=1;i<n;i++){
            temp[i]=temp[i-1]+nums[i];
        }
        
        for(int i=0;i<n-1;i++){
            if(temp[i]>=(temp[n-1]-temp[i])){
                count++;
            }
        }
        return count;
    }
};