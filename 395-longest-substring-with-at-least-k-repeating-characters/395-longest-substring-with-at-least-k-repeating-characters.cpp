class Solution {
public:
    int solve(string &s,int start,int end,int k){
        if (end < k) return 0;
        int countMap[26] = {0};
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
            return max(solve(s, start, mid, k),
                    solve(s, midNext, end, k));
        }
        return (end - start);
    }
    int longestSubstring(string s, int k) {
        int n=s.size();
        return solve(s,0,n,k);
    }
};