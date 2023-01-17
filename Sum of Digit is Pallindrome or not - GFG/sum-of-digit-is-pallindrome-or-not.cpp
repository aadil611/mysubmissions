//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int reverse(long long int n){
        long long int res=0;
        while(n){
            int rem = n % 10;
            res = res * 10  + rem;
            n /= 10;
        }
        return res;
    }
    
    bool isPal(int n){
        return n == reverse(n);
    }
    
    int isDigitSumPalindrome(int N) {
        long long int digit_sum = 0;
        int temp = N;
        while(temp){
            digit_sum += temp % 10;
            temp /= 10;
        }
        
        return isPal(digit_sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends