class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int score=0;
        int n=card.size();
        for(int i=0;i<k;i++){
            score+=card[i];
        }
        int temp=score;
        for(int i=k-1;i>=0;i--){
            temp-=card[i];
            temp+=card[n-k+i];
            score=max(score,temp);
        }
        return score;
    }
};