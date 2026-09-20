def solve():
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    print(a[n - 1] - a[0] + min(abs(s - a[0]) , abs(s - a[n - 1])))

for _ in range(int(input())):
    solve()
