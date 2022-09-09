class Solution {
public:
    bool check(int count[],int k){
        for(int i=0;i<26;i++){
            if(count[i]!=0&&count[i]<k){
                return 0;
            }
        }
        return 1;
    }
    int longestSubstring(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int count[26]={0};
            for(int j=i;j<s.size();j++){
                count[s[j]-'a']++;
                if(count[s[j]-'a']<k){
                    continue;
                }
                if(check(count,k)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};