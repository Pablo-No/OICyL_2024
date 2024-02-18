import sys
s = input()
d = 0
for t in sys.stdin:
    for c in t[:-1]:
        print(str(ord(c)^((ord(s[d%len(s)])+d//len(s))%256))+" ", end="")
        d += 1
    print()
