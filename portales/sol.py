s = input()
n = int(input())
bs = ""
bd = 1_000_000
for _ in range(n):
    t = input()
    d = 0
    for c1,c2 in zip(s,t):
        d += c1 != c2
    if d < bd: bd,bs = d,t
print(bs)