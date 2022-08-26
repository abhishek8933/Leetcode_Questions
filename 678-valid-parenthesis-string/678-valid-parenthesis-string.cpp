class Solution {
public:
    bool checkValidString(string s) {
         stack<char> st;        // insert indices of '('
        stack<char> sr;         // insert indices of '*'
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == '*')
                sr.push(i);
            else            // when ')' appears        
            {
                if(!st.empty())
                    st.pop();
                else if(!sr.empty())     // case = "*(()*))"
                    sr.pop();
                else                        // case =  ")*()"  
                    return false;
            }
        }
        
        // this part executes only if st is not empty i.e. "(" are not balanced till now.
        while(!st.empty())    // to balance the "(" 
        {
            if(sr.empty())   // if no "*" are present then we can't balace the "("
                return false;
            else if(st.top() < sr.top())    // to balance "(" we neeed "*" to the right side of "("
            {
                st.pop();                 // case = "(*(**)"
                sr.pop();
            }
            else         // case = "***(()"
                return false;
        }
        return true;
    }
};