for _ in range(int(input())):
    n, k = map(int,input().split())
    for i in range(k):
        print(i,end=" ")
    for i in range(n-1,k-1,-1):
        print(i,end=" ")
    print()