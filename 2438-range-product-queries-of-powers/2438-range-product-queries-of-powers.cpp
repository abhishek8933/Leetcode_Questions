class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
         int m = 1e9+7;
        vector<int> temp;
        vector<int> ans;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                temp.push_back(1<<i);
            }
        }
        
        for(auto q:queries){
            int i=q[0];
            long p=temp[i++];
            while(i<=q[1]){
                p=(p*temp[i])%m;
                i++;
            }
            ans.push_back(p);
            
        }
        return ans;
        
        
    }
};