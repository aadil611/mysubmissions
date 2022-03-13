class Solution {
public:
    
    bool isValid(string str) {
        int n=str.length();
        if(n<=1 || n%2==1)
            return false;
        map<char,char> opp{{'}','{'},{']','['},{')','('}};
        stack<char> st;
        for(int i=0;i<n;i++){
            if(str[i]=='{' || str[i]=='(' || str[i]=='[')
                st.push(str[i]);
            else
            {
                if(!st.empty() && st.top() == opp[str[i]])
                    st.pop();
                else
                    return false;   
            }
        }
        return st.empty();
    }
};