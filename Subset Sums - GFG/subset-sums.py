#User function Template for python3
class Solution:
    def helper(self,ind,arr,sum,res):
        if ind == len(arr):
            res.append(sum)
            return
        self.helper(ind + 1,arr,sum + arr[ind],res)
        self.helper(ind + 1,arr,sum ,res)
    
	def subsetSums(self, arr, N):
		res = []
		self.helper(0,arr,0,res)
		return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        ans.sort()
        for x in ans:
            print(x,end=" ")
        print("")

# } Driver Code Ends