class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long sum=0;
        int cnt1=0;
        int cnt2=0;
        for(char&c:text){
            if(c==pattern[1]){
                sum+=cnt1;
                cnt2++;
            }
            if(c==pattern[0]){
                cnt1++;
            }
        }
        return sum+max(cnt1,cnt2);
    }
};