def check(n,k,l):
    count=0
    for i in range(n-k+1):
        x=0
        for j in range(i,i+k):
            x|=l[j]
        
           
            if(x%2!=0):
                count+=1
                break
        
    return count

def solve():
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    print(check(n,k,l))
    
for _ in range(int(input())):
    solve()