n, m, k = map(int, input().split())
res = 0
for i in range(k + 1):
    res = max(res, min((n - i) // 2, m - (k - i)))
if res < 0:
    res = 0
print(res)