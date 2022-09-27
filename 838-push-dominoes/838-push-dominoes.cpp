class Solution {
public:
    string pushDominoes(string s) {
        string ans="";
        int right=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                if(right==-1){
                    for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                            s[j] = 'L';  
                    } 
                }
                else{
                    int j=i-1;
                    int k=right+1;
                    while(j>k){
                        s[k]='R';
                        s[j]='L';
                        j--;
                        k++;
                    }
                    right=-1;
                }
            }
            else if(s[i]=='R'){
                if(right!=-1){
                    for(int j=right+1;j<i;j++){
                        s[j]='R';
                    }
                }
                right=i;
            }
        }
        if (right != -1) {
        for (int j = right + 1; j < s.size(); ++j) s[j] = 'R';
    }
        return s;
    }
};