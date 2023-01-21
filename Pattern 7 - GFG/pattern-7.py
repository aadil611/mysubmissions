#User function Template for python3

class Solution:
    def printTriangle(self, N):
        
        for i in range(N):
            for j in range(2*N):
                ch = "*" if j >= N - i - 1 and j <= N + i - 1  else " " if j <= N else ""
                print(ch,end="")
            print()

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ob.printTriangle(N)
# } Driver Code Ends