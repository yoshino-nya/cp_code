for _ in range(int(input())):
    x, y, z = map(int, input().split())

    sum = x + y + z
    l = sum // 2 + 1
    l = max(l, x)
    r = x + z

    if l <= r:
        print(r - l + 1)
    else:
        print(0)