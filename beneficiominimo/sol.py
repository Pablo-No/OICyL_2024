import heapq
from bisect import bisect_left
from collections import defaultdict

ftsum = 0
# Fenwick Tree
def ftch(p, v):
    global ftsum
    ftsum += v
    while p < len(ft):
        ft[p] += v
        p += (p)&(-p)
def ftrsq(p):
    ans = 0
    while p:
        ans += ft[p]
        p -= (p)&(-p)
    return ans
def ftgetp(v):
    st = 2**25
    p = 0
    cv = 0
    while st:
        if p+st < len(ft) and cv+ft[p+st] <= v:
            p += st    
            cv += ft[p]
        st //= 2
    return opts[p]
# Helper functions
def ch(opa, opb, ch):
    if opb%2 == 1 and opa%2 == 0:
        gain = opb//2 - opa//2
        fpos[gain] += ch
        heapq.heappush(pos, gain)
def add(op):
    pt = ftrsq(bisect_left(opts, op))
    if pt != 0:
        ch(ftgetp(pt-1), op, +1)
    if pt != ftsum:
        ch(op, ftgetp(pt), +1)
    if pt != 0 and pt != ftsum:
        ch(ftgetp(pt-1), ftgetp(pt), -1)
    ftch(bisect_left(opts, op)+1, +1)
def rem(op):
    ftch(bisect_left(opts, op)+1, -1)
    pt = ftrsq(bisect_left(opts, op))
    if pt != 0:
        ch(ftgetp(pt-1), op, -1)
    if pt != ftsum:
        ch(op, ftgetp(pt), -1)
    if pt != 0 and pt != ftsum:
        ch(ftgetp(pt-1), ftgetp(pt), +1)
# Main part
def main():
    global opts
    global fpos
    global ft
    global pos
    a, b = map(int, input().split())
    q = int(input())
    f = defaultdict(int)
    qs = [0]*q
    allopts = [0]*(2*q)
    fpos = defaultdict(int)
    pos = []
    for i in range(q):
        line = input().split()
        c = line[0]
        v = int(line[1])
        qs[i] = (c, v)
        allopts[2*i] =  (v*a+1)*2
        allopts[2*i+1] = (v*b)*2+1
    opts = sorted(set(allopts))
    ft = [0]*(len(opts)+1)
    ftsum = 0
    for c,v in qs:
        opc = (v*a+1)*2
        opv = (v*b)*2+1
        if c == '+':
            f[v] += 1
            if f[v] == 1:
                add(opc)
                add(opv)
        else:
            f[v] -= 1
            if f[v] == 0:
                rem(opc)
                rem(opv)
        while len(pos) > 0 and fpos[pos[0]] == 0: heapq.heappop(pos)
        if len(pos) == 0: print("0")
        else: print(pos[0]+1)
main()