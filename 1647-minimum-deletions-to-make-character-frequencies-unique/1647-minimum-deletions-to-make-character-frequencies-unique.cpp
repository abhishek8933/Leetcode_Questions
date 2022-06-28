class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        int deletion=0;
        set<int> set;
        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count[i]>0){
                while(set.count(count[i])){
                    deletion+=1;
                    count[i]-=1;
                }
                if(count[i]>0){
                 set.insert(count[i]);
                }
            }
        }
        return deletion;
    }
};