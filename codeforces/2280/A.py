
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    cnt_a = 0
    for x in a:
        if x % 2 == 1:
            cnt_a += 1

    cnt_b = 0
    for x in b:
        if x % 2 == 1:
            cnt_b += 1

    if cnt_a < cnt_b:
        print("YES" if k % 2 == 1 else "NO")
    elif cnt_a == cnt_b:
        print("YES")
    else:
        print("YES" if k % 2 == 0 else "NO")