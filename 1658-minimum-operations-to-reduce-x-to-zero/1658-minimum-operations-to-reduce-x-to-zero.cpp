class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> map;
        map[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            map[sum]=i;
        }
        if(x>sum){
            return -1;
        }
        int longest=0;
        sum-=x;
        int val=0;
        for(int i=0;i<n;i++){
            val+=nums[i];
            if(map.count(val-sum)){
                if(val-sum==0){
                    longest=max(longest,i-map[val-sum]+1);
                }
                else{
                    longest=max(longest,i-map[val-sum]);
                }
            }
        }
        if(longest==0 && sum==0){
            return n;
        }else if(longest==0 && sum!=0){
            return -1;
        }else{
            return n-longest;
        }
    }
};