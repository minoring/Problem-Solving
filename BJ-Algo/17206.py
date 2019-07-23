input()
n = list(map(int,(input().split())))
m = max(n)+1
g = [0]*m
for num in range(1, m):
    g[num] = g[num - 1]
    if not (num%3 and num%7):
        g[num] += num
print(*[g[i] for i in n])