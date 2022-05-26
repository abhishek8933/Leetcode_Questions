class Solution {
public:
    int count_bits(int num){
        int count=0;
        while(num>0){
            count++;
            num=num&(num-1);
        }
        return count;
    }
    bool is_prime(int num){
         if (num <=1){ //0 and 0 is not prime
            return false;
        }
        int i =2;
        while (i <= (num/2)){
            if (num % i == 0){
                return false;
            }
            i++;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int ans=count_bits(i);
            if(is_prime(ans)){
                count++;
            }
        }
        return count;
    }
};