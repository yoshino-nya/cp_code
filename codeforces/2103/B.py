for _ in range(int(input())):
    n = int(input())
    s = input()
    cost = n
    cur = 0
    cnt = 0
    cc = 0
    for i in range(n):
        if s[i]=='0':
            cc+=1
        if int(s[i])!=cur:
            cur^=1
            cost+=1
            if s[i]=='1':
                cnt+=1
    # print(cost)
    if s[0]=='0':
        # print(s,cnt,s[n-1])
        if cnt==1 and s[n-1]!='1':
            cost-=1
        elif cnt>1:
            cost-=2
    else:
        if cnt>=2 and cc:
            cost-=2
        elif cc:
            cost-=1
    print(cost)
