class Solution {
public:
    int count(string s){
        if(s[0]=='?' && s[1]=='?'&&s[2]=='?'&&s[3]=='?'){
            return 4;
        }
        return 0;
    }
    int countTime(string time) {
        if(count(time)==4){
            return 24*60;
        }
        int ans=1;
        
        if(time[0]=='?' && time[1]!='?'){
            if(time[1]<='3'){
                ans*=3;
            }else{
                ans*=2;
            }
        }
        if(time[0]!='?' && time[1]=='?'){
            if(time[0]=='2'){
                ans*=4;
            }else{
                ans*=10;
            }
        }
        if(time[0]=='?' && time[1]=='?'){
            ans*=24;
        }
        //minute
        if(time[3]=='?' && time[4]=='?'){
            ans*=60;
        }
        if(time[3]!='?'&&time[4]=='?'){
            ans*=10;
        }
        if(time[3]=='?' && time[4]!='?'){
            ans*=6;
        }
        
        return ans;
        
    }
};