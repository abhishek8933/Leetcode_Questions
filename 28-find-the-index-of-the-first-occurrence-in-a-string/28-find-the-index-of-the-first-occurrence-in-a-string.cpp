class Solution {
public:
    int strStr(string s, string p) {
       int j=0;
        if(p.size()>s.size()){
            return -1;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==p[j]){
                j++;
            }
            else{
                i=i-j;
                j=0;
            }
            if(j==p.size()){
                return i-j+1;
            }
        }
        return -1;
    }
};