a, b = input().split()
dif = len(b) - len(a)
r = 51
for d in range(0, dif + 1):
    s = 0
    for i in range(len(a)):
        if a[i] != b[i + d]:
            s += 1
    r = min(r, s)
print(r)