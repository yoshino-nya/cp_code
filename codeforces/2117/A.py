for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    last = - 1
    for i in range(n):
        if a[i] == 1:
            if last == -1:
                last = i + x - 1
            elif i > last:
                print("NO")
                break
    else:
        print("YES")
               