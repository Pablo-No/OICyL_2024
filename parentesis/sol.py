N = 55
M = 205
t = int(input())
for _ in range(t):
    dp = [[0] * (N*M*2) for _ in range(N)]
    line = input()
    lin = iter(line.split())
    ig = int(next(lin))
    dp[0][N*M] = 1
    cnt = 0
    for c, x in zip(lin, lin):
        x = int(x)
        for v in range(N*M*2):
            p = dp[cnt][v]
            if p:
                if c == '-': p += 1
                dp[cnt + 1][v + (x if p % 2 else -x)] = max(dp[cnt + 1][v + (x if p % 2 else -x)], p)
                p -= 1
                if c != '-' or p > 1: dp[cnt + 1][v + (x if p % 2 else -x)] = max(dp[cnt + 1][v + (x if p % 2 else -x)], p)
        cnt += 1
    ans = sum(1 for i in range(N * M * 2) if dp[cnt][i] != 0)
    print(ans)
