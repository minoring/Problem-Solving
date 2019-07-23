M = 10000
p = [0, 0] + [1] * (M - 1)

for i in range(2, int(M ** 0.5) + 1):
    if p[i]:
        for j in range(i + i, M + 1, i):
            p[j] = 0

for _ in range(int(input())):
    n = int(input())
    res = [
        (x, n - x) 
        for x, y in enumerate(p[: n // 2 + 1]) 
        if y and p[n - x]
    ][-1]
    print(*res)
