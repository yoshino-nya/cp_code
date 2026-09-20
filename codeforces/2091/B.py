for _ in range(int(input())):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    ans=0
    lst=-1
    for i in range(n):
        if (i-lst)*a[i]>=x:
            lst=i
            ans+=1
    print(ans)