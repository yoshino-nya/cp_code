# 4 9 16 36 49
# 3 8 15 35 
def solve():
    x = int(input())
    if x % 3 == 0:
        if x > 9:
            print("Yes")
        else:
            print("No")
    elif x % 3 == 1:
        print("Yes")
    else:
        if x > 16:
            print("Yes")
        else:
            print("No")

for _ in range(int(input())):
    solve()