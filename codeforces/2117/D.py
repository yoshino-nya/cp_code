'''
i * x + (n - i + 1) * y = a[i]

(i + 1) * x + (n - i) * y = a[i + 1]

a[i + 1] - a[i] = x - y

a[1] = x + n * y, a[1] - d = (n + 1) * y
a[n] = x * n + y, x * (n + 1) = a[n] + d

(x + 1) * 2 = 101 + 51, 152
'''

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = a[1] - a[0]
    for i in range(2, n):
        if a[i] - a[i - 1] != d:
            print("NO")
            break
    else:
        if (a[n - 1] + d) % (n + 1) == 0:
            x = (a[n - 1] + d) // (n + 1)
            y = x - d
            if x >= 0 and y >= 0:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")