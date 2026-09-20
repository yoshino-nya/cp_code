for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    lo = 0
    hi = n+1
    def check(x):
        st = set()
        cnt=0
        for i in range(n):
            if a[i]<x:
                st.add(a[i])
            if len(st)==x:
                cnt+=1
                st.clear()
        return cnt>=k
                
    while lo<hi-1:
        mid = (lo+hi)>>1
        if check(mid):
            lo=mid
        else:
            hi=mid
    print(lo)