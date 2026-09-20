for _ in range(int(input())):
    a=[0]*10
    # print(a)
    n = int(input())
    b=list(map(int,input().split()))
    for i in range(n):
        a[b[i]]+=1
        if a[0]>=3 and a[1]>=1 and a[2]>=2 and a[3]>=1 and a[5]>=1:
            print(i+1)
            break
    else:
        print(0)