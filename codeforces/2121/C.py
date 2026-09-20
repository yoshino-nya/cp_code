def solve():
    n, m = map(int, input().split())
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))
    
    r = [[0] * 101 for _ in range(n)]
    c = [[0] * 101 for _ in range(m)]
    cnt = [0] * 101
    mx = 0
    for i in range(n):
        for j in range(m):
            r[i][a[i][j]] += 1
            c[j][a[i][j]] += 1
            cnt[a[i][j]] += 1
            mx = max(mx, a[i][j])

    for i in range(n):
        for j in range(m):
            # print(i, j)
            if r[i][mx] + c[j][mx] - (a[i][j] == mx) == cnt[mx]:
                # print(i, j, r[i][mx], c[j][mx], )
                print(mx - 1)
                return
    print(mx)
for _ in range(int(input())):
    solve()
