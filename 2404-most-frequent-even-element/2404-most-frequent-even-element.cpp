class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                map[nums[i]]++;
            }
        }
        int element=-1;
        int ans=0;
        for(auto i:map){
            if(i.second>ans ||( i.first<element && i.second==ans)){
                ans=i.second;
                element=i.first;
            }
        }
        return element;
    }
};