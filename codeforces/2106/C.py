for _ in range(int(input())):
    n, k = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sum = -1
    for i in range(n):
        if b[i] != -1:
            if sum == -1:
                sum = a[i] + b[i]
            elif a[i] + b[i] != sum:
                print(0)
                break
    else:
        if sum == -1:
            a.sort()
            print(max(a[0]+k-a[n-1]+1,0))
        else:
            for i in range(n):
                if b[i] == -1:
                    if sum - a[i] > k or sum -a[i] < 0:
                        print(0)
                        break
            else:
                print(1)