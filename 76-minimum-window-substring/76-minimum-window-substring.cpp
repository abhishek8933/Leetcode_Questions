class Solution {
public:
    string minWindow(string s, string p) {
        if(p.size()>s.size()){
            return "";
        }
        unordered_map<char,int> map;
        for(auto it:p){
            map[it]++;
        }
        int count=p.size();
        int i=0,j=0,ans=INT_MAX;
        int start=-1;
        while(j<s.size()){
            if(map[s[j]]>0){
                count--;
            }
            map[s[j]]--;
            while(count==0){
                if(ans>j-i+1){
                    ans=j-i+1;
                    start=i;
                }
                map[s[i]]++;
                if(map[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return start==-1?"":s.substr(start,ans);
    }
};