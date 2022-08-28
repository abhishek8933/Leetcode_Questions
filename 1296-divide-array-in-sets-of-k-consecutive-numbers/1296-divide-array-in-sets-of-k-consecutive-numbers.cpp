class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
            int n = nums.size();
        
        if(n % k != 0)
        {
            return false;
        }
        
        map<int, int> mp;
        
        for(int& num: nums)
        {
            mp[num]++;
        }
        
        int l = n/k;
        
        
        for(int i = 1; i <= l; i++)
        {
            auto it = mp.begin();
            int tmp = it->first;
            
            for(int j = tmp; j < tmp + k; j++)
            {
                if(mp.find(j) == mp.end())
                {
                    return false;
                }
                
                mp[j]--;
                if(mp[j] == 0)
                {
                    mp.erase(j);
                }
            }
        }
        
        
        return true;
    }
};