n = int(input())
s = list(input())
add = 0
for i in range(n):
    x = ord(s[i])
    if add:
        if x + add > 97 + 25:
            break
        else:
            s[i] = chr(x + add)
    else:
        add = 97 + 25 - x
        s[i] = 'z'
for i in s:
    print(i, end = "")
 