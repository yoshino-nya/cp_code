n = int(input())
a = list(map(int, input().split()))
k = int(input())
ans = 0
for x in a:
    if x >= k:
        ans += 1

print(ans)