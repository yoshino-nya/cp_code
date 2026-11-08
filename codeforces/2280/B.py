"""
1...0
"""

import sys


def ask(l:int, r:int):
    print(f"? {l} {r}")
    sys.stdout.flush()
    return int(input())

for _ in range(int(input())):
    n = int(input())
    cnt = ask(1, n)
    if cnt == 0:
        print("NO")
    elif ask(1, cnt) == cnt:
        print("! NO")
    else:
        print("! YES")
    sys.stdout.flush()