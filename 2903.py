N = int(input())
d = [2] + [0] * N
for i in range(1, N + 1):
    d[i] = d[i - 1] + d[i - 1] - 1
print(d[N] ** 2)
