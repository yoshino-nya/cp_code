for _ in range(int(input())):
    xor = 0
    n = int(input())
    a = list(map(int, input().split()))
    for i in a:
        xor ^= i
    if xor:
        print("Yes")
    else:
        print("No")