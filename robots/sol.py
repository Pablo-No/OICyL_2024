import heapq

K = 4
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
N = 405
INF = 1e18+8
a = [[0] * N for _ in range(N)]
d = [[INF] * N for _ in range(N)]
p = [[(0, 0)] * N for _ in range(N)]
def valid(x, y, n, m):
    return x >= 0 and x < n and y >= 0 and y < m and a[x][y] != -1
n, m = map(int, input().split())
sx = sy = ex = ey = 0
for i in range(n):
    line = input()
    for j,s in enumerate(line.split()):
        if s == "A":
            sx, sy = i, j
            a[i][j] = 0
        elif s == "B":
            ex, ey = i, j
            a[i][j] = 0
        else:
            a[i][j] = int(s)
        d[i][j] = INF
pq = []
d[sx][sy] = 0
heapq.heappush(pq, (0, (sx, sy)))
while pq:
    cd, (cx, cy) = heapq.heappop(pq)
    if cd != d[cx][cy]:
        continue
    for k in range(K):
        nx, ny = cx + dx[k], cy + dy[k]
        if not valid(nx, ny, n, m): continue
        if cd + a[nx][ny] >= d[nx][ny]: continue
        d[nx][ny] = cd + a[nx][ny]
        heapq.heappush(pq, (d[nx][ny], (nx, ny)))
        p[nx][ny] = (cx, cy)
cp = (ex, ey)
ans = []
while cp != (sx, sy):
    ans.append(cp)
    cp = p[cp[0]][cp[1]]
ans.append((sx, sy))
for x, y in reversed(ans):
    print(x, y)
