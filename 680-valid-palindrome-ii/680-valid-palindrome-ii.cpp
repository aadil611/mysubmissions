class Solution {
public:
    bool ispalindrome(string str,int i,int j){
        while(i<j){
            if(str[i++]!=str[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int len=s.length();
        int i=0,j=len-1,cnt=0;
        if(s[i]!=s[j] && len==3)
            return false;
        while(i<j){
            if(s[i]!=s[j])
                return (ispalindrome(s,i+1,j) || ispalindrome(s,i,j-1));
            i++;
            j--;
        }
        return true;
    }
};