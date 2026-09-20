def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = []
    for i in range(n):
        if a[i] > b[i]:
            a[i], b[i] = b[i], a[i]
            ans.append([3, i + 1])
    while True:
        for i in range(n - 1):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                ans.append([1, i + 1])
                break
        else:
            break
    while True:
        for i in range(n - 1):
            if b[i] > b[i + 1]:
                b[i], b[i + 1] = b[i + 1], b[i]
                ans.append([2, i + 1])
                break
        else:
            break
    # print(a)
    # print(b)
    print(len(ans))
    for x in ans:
        print(x[0], x[1])
for _ in range(int(input())):
    solve()
