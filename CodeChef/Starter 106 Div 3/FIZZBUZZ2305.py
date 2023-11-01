# cook your dish here

def solve():
    n=int(input())
    if(n==1 or n%2==0):
        print("Bob")
    else:
        print("Alice")
for _ in range(int(input())):
    solve()