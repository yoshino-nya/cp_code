mod = 1000000007
def solve():
    a, b, k = map(int, input().split())
    n = ((a - 1) * k + 1) % mod
    # (n, a) * (b - 1) * k
    # n * (n - 1) * (n - a + 1)
    # n! / m!
    fz = 1
    for i in range(a):
        fz = fz * (n - i) % mod
    fm = 1
    for i in range(1, a + 1):
        fm = fm * i % mod
    ans = fz * pow(fm, mod - 2, mod) % mod * (b - 1) % mod * k % mod + 1
    print(n, ans % mod)
for _ in range(int(input())):
    solve()