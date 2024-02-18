from collections import defaultdict
from bisect import bisect_left as lower_bound
from bisect import bisect_right as upper_bound
class FenwickTree:
    def __init__(self, x):
        bit = self.bit = list(x)
        size = self.size = len(bit)
        for i in range(size):
            j = i | (i + 1)
            if j < size:
                bit[j] += bit[i]
    def update(self, idx, x):
        while idx < self.size:
            self.bit[idx] += x
            idx |= idx + 1
    def __call__(self, end):
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x
    def find_kth(self, k):
        idx = -1
        for d in reversed(range(self.size.bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < self.size and self.bit[right_idx] <= k:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1, k
class SortedList:
    block_size = 700
    def __init__(self, iterable=()):
        self.macro = []
        self.micros = [[]]
        self.micro_size = [0]
        self.fenwick = FenwickTree([0])
        self.size = 0
        for item in iterable:
            self.insert(item)
    def insert(self, x):
        i = lower_bound(self.macro, x)
        j = upper_bound(self.micros[i], x)
        self.micros[i].insert(j, x)
        self.size += 1
        self.micro_size[i] += 1
        self.fenwick.update(i, 1)
        if len(self.micros[i]) >= self.block_size:
            self.micros[i:i + 1] = self.micros[i][:self.block_size >> 1], self.micros[i][self.block_size >> 1:]
            self.micro_size[i:i + 1] = self.block_size >> 1, self.block_size >> 1
            self.fenwick = FenwickTree(self.micro_size)
            self.macro.insert(i, self.micros[i + 1][0])
    def pop(self, k=-1):
        i, j = self._find_kth(k)
        self.size -= 1
        self.micro_size[i] -= 1
        self.fenwick.update(i, -1)
        return self.micros[i].pop(j)
    def __getitem__(self, k):
        i, j = self._find_kth(k)
        return self.micros[i][j]
    def lower_bound(self, x):
        i = lower_bound(self.macro, x)
        return self.fenwick(i) + lower_bound(self.micros[i], x)
    def _find_kth(self, k):
        return self.fenwick.find_kth(k + self.size if k < 0 else k)
    def __len__(self):
        return self.size

opts = SortedList()
pos = SortedList()

def ch(opa, opb, ch):
    opa = (opa//2, opa%2)
    opb = (opb//2, opb%2)
    if opb[1] == 1 and opa[1] == 0:
        gain = opb[0] - opa[0]
        if ch == 1:
            pos.insert(gain)
        if ch == -1:
            pos.pop(pos.lower_bound(gain))

def add(op):
    pt = opts.lower_bound(op)
    if pt != 0:
        ch(opts[pt-1], op, +1)
    if pt != len(opts):
        ch(op, opts[pt], +1)
    if pt != 0 and pt != len(opts):
        ch(opts[pt-1], opts[pt], -1)
    opts.insert(op)

def rem(op):
    opts.pop(opts.lower_bound(op))
    pt = opts.lower_bound(op)
    if pt != 0:
        ch(opts[pt-1], op, -1)
    if pt != len(opts):
        ch(op, opts[pt], -1)
    if pt != 0 and pt != len(opts):
        ch(opts[pt-1], opts[pt], +1)

def main():
    a, b = map(int, input().split())
    q = int(input())
    f = defaultdict(int)

    for _ in range(q):
        line = input().split()
        c = line[0]
        v = int(line[1])
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
        if len(pos) == 0: print("0")
        else: print(pos[0]+1)
main()