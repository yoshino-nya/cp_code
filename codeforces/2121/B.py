def solve():
    n = int(input())
    s = input()
    vis = [0] * 26
    vis[ord(s[0]) - 97] = 1
    vis[ord(s[n - 1]) - 97] = 1
    for i in range(1, n - 1):
        if vis[ord(s[i]) - 97]:
            print("Yes")
            return
        vis[ord(s[i]) - 97] = True
    print("No")

for _ in range(int(input())):
    solve()
