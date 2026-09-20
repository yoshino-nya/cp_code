for _ in range(int(input())):
    n = int(input())
    for i in range(1,n+1):
        if i%2==0:
            print(3,end=" ")
        else:
            print(4,end=" ")
    print()