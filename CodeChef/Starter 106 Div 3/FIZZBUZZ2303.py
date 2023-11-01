# cook your dish here
def nCr(n, r):
 
    return (fact(n) / (fact(r) 
                * fact(n - r)))
 
# Returns factorial of n
def fact(n):
    if n == 0:
        return 1
    res = 1
     
    for i in range(2, n+1):
        res = res * i
         
    return res

def solve():
    n=int(input())
    print(int(nCr(n,2))*2)
    



for _ in range(int(input())):
    solve()