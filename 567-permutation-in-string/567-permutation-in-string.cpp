class Solution {
public:
    bool isequal(vector<int>&freq1,vector<int>&freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int k=s1.size();
        for(char &c:s1){
            freq1[c-'a']++;
        }
        int i=0,j=0;
        while(j<s2.size()){
           freq2[s2[j]-'a']++;
            if(j-i+1==k){
                if(isequal(freq1,freq2)){
                    return true;
                }
            }
            if(j-i+1<k){
                j++;
            }
                else{
                    freq2[s2[i]-'a']--;
                    i++;
                    j++;
                }
        }
        return false;
    }
};