for _ in range(int(input())):
    n , m = map(int,input().split())
    a = list(input().split())
    b = [[]] * m
    cnt = [0]*n
    for i in range(m):
        b[i] = list(input().split())
        for j in range(n):
            if b[i][j]==a[j]:
                cnt[j]+=1
    
    # print(cnt)

    ans = 1000000000
    for i in range(m):
        now = n
        for j in range(n):
            if b[i][j]!=a[j]:
                # print(b[i][j],a[j])
                if cnt[j]>=1:
                    now+=2
                else:
                    break
        else:
            ans=min(ans,now)
    if ans==1000000000:
        print(-1)
    else:
        print(ans)