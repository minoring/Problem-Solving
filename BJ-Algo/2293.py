n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

MAX_NUM = 10000
d = [0] * (MAX_NUM + 1)
d[0] = 1

for coin in coins:
    for j in range(1, k + 1):
        if j - coin >= 0:
            d[j] += d[j - coin]
print(d[k])

# TOP-DOWM made stack overflow.
# e.g. 1 10000 1
# def solve(num):
#     if num <= 0:
#         return 0
#     if d[num]:
#         return d[num]
#     max_comb = max([solve(num - coin) for coin in coins])
#     if max_comb == 0:
#         return 0
#     else:
#         d[num] = max_comb + 1
#         return d[num]
# print(solve(k))