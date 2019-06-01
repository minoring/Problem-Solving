n = int(input())
c = [int(input()) for _ in range(n)]
c = [0] + c

z = [0] * (n + 1)
o = [0] * (n + 1)
t = [0] * (n + 1)

o[1] = c[1]

for i in range(2, n + 1):
    z[i] = max(o[i - 1], t[i - 1])
    o[i] = max(z[i - 1], z[i - 2]) + c[i]
    t[i] = o[i - 1] + c[i]

print(max(z[n], max(o[n], t[n])))