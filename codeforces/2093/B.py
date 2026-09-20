for _ in range(int(input())):
    n = input()
    # n.sort()
    
    cnt = 0
    # x/len 是答案
    # 
    ans = 1000
    res = len(n)-1
    for i in range(len(n)):
        if n[i]=='0':
            cnt+=1
        else:
            ans = int(n[i])/(cnt+1)
    cnt = 0
    for i in range(len(n)):
        if n[i]=='0':
            cnt+=1
        elif int(n[i])/(cnt+1)==ans:
            res = min(res,len(n)-(cnt+1))
    print(res)
