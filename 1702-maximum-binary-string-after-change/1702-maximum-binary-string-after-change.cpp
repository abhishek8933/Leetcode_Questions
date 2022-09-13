class Solution {
public:
    string maximumBinaryString(string binary) {
        int zeroes=0,ones=0;
        int n=binary.length();
        for(auto &c:binary){
            if(c=='0'){
                zeroes++;
            }else if(zeroes==0){
                ones++;
            }
            c='1';
        }
        if(ones<n){
            binary[ones+zeroes-1]='0';
        }
        return binary;
    }
};