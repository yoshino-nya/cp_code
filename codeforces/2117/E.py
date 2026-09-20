for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    r1 = [[-1] * 2 for i in range(n + 1)]
    r2 = [[-1] * 2 for i in range(n + 1)]
    a.reverse()
    b.reverse()
    if a[0] == b[0]:
        print(n)
        continue
    r1[a[0]][0] = 0
    r2[b[0]][0] = 0
    for i in range(1, n):
        if a[i] == b[i]:
            print(n - i)
            break
        else:
            if r1[b[i]][i & 1] != -1:
                print(n - i)
                break
            if r2[b[i]][(i & 1) ^ 1] != -1:
                print(n - i)
                break
            
            if r2[a[i]][i & 1] != -1:
                print(n - i)
                break
            if r1[a[i]][(i & 1) ^ 1] != -1:
                print(n - i)
                break

            if r1[b[i]][(i & 1) ^ 1] != -1 and r1[b[i]][(i & 1) ^ 1] != (i - 1) :
                print(n - i)
                break
            if r2[b[i]][(i & 1)] != -1 and r2[b[i]][(i & 1)] != (i - 1):
                print(n - i)
                break

            if r2[a[i]][(i & 1) ^ 1] != -1 and r2[a[i]][(i & 1) ^ 1] != (i - 1):
                print(n - i)
                break
            if r1[a[i]][(i & 1)] != -1 and r1[a[i]][(i & 1)] != (i - 1):
                print(n - i)
                break
        
        if r1[a[i]][i & 1] == -1:
            r1[a[i]][i & 1] = i
        if r2[b[i]][i & 1] == -1:
            r2[b[i]][i & 1] = i
            
    else:
        print(0)