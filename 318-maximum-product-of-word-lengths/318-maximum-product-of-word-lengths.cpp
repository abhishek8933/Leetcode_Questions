class Solution {
public:
    int check(string x,string y){
        int count[26]={0};
        bool ans=false;
        for(int i=0;i<x.size();i++){
            count[x[i]-'a']++;
        }
        for(int i=0;i<y.size();i++){
            if(count[y[i]-'a']>0){
                return 0;
            }
        }
        return x.size()*y.size();
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    ans=max(ans,check(words[i],words[j]));
            }
        }
        return ans;
    }
};