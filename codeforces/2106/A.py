for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = 0
    for i in range(n):
        if s[i]=='1':
            cnt+=1
    ans = n*cnt
    for i in range(n):
        if s[i]=='1':
            ans-=1
        else:
            ans+=1
    print(ans)