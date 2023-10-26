class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    

    def solve(self, A, B):
        if(len(A)-1==B):
            return sum(A)
        length=len(A)
        s=0
        for i in range(B):
            s+=A[i]
        i=B-1
        j=length-1
        current=s
        while(i>=0):
    
            current=((current-A[i])+A[j])
            s=max(s,current)
            i-=1
            j-=1
        
        return s
