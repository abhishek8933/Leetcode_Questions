class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        int mod;
        while(columnNumber>0){
            columnNumber--;
            mod=columnNumber%26;
            res+=('A'+mod);
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};