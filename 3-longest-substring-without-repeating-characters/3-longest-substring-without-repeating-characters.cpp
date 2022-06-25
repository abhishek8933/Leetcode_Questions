class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         vector<int> cache(256,-1);
        int start=-1,maxres=0;
        for(int i=0;i<s.size();i++){
            start=max(start,cache[s[i]]);
            cache[s[i]]=i;
            maxres=max(maxres,i-start);
        }
        return maxres;
    }
};