mod = 10**9+7

n = int(input())

cnt = 1
ans = 0

for i in range(1,n):
    ans+=3*cnt%mod
    ans%=mod
    cnt*=2
    cnt%=mod

ans=(ans-2)%mod

if n==1:
    print(0)
else:
    print(ans)
