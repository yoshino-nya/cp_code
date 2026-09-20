import math
n = int(input())
st = set()
def calc(x):
    lo=0
    hi=10000001
    while lo<hi-1:
        mid=(lo+hi)>>1
        if mid*mid*mid<=x:
            lo=mid
        else:
            hi=mid
    return lo
for i in range(1,5000000):
    x = i*i*i
    st.add(x)
    if x-n in st:
        print(i,calc(x-n))
        break
else:
    print(-1)
