n = int(input())
r = 0
for _ in range(n):
    s = str(input().strip())
    st = []
    for c in s:
        if st and st[-1] == c:
            st.pop()
        else:
            st.append(c)
    if not st:
        r += 1
print(r)