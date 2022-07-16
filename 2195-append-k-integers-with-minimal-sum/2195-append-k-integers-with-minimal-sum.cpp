class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        long long ans=long(k)*long(k+1)/2;
        nums.clear();
        
        for(auto i:s){
            nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=k){
                ans-=nums[i];
                ans+=k+1;
                k++;
            }else{
                break;
            }
        }
        return ans;
        
        
    }
};