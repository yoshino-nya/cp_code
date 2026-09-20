from math import sqrt
n = input()

x = 1

for i in n:
    x *= int(i)

y = int(sqrt(x))
while y * y > x:
    y -= 1
if y * y == x:
    print("YES")
else:
    print("NO")