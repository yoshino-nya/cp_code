import math
for _ in range(int(input())):
    n,a,b,c=map(int,input().split())
    ans = n//a-n//math.lcm(a,b)-n//math.lcm(a,c)+n//math.lcm(a,b,c)+n//c
    print(ans)