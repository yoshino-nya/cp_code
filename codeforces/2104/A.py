for _ in range(int(input())):
    a, b ,c = map(int, input().split())
    d = (a + b + c) // 3
    if b <= d and a + b + c == 3 * d:
        print("YES")
    else:
        print("NO")