class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(k--){
            int top=pq.top();
            pq.pop();
            pq.push(-1*top);
        }
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans+=top;
        }
        return ans;
    }
};