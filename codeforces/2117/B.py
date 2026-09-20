# 1 3 5 6 4 2
# 1 3 5 6 4 2

for _ in range(int(input())):
    n = int(input())
    a = [0] * n
    for i in range(n):
        if i & 1:
            a[i // 2] = i + 1
        else:
            a[n - 1 - i // 2] = i + 1
    for i in a:
        print(i, end = " ")
    print()
        