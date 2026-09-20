n = int(input())

a = list(map(int, input().split()))

for i in range(n - 1):
    sum = 0
    for j in range(i, n - 1):
        sum += a[j]
        print(sum, end=" ")
    print()