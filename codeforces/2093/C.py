def is_prime(x):
    if x==1:
        return False
    i=2
    while i*i<=x:
        if x%i==0:
            return False
        i+=1
    return True

for _ in range(int(input())):
    x,k=map(int,input().split())
    if k!=1:
        if x==1 and k==2:
            print("YES")
        else:
            print("NO")
    else:
        if is_prime(x):
            print("YES")
        else:
            print("NO")