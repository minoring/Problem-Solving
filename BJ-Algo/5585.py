n = int(input())
n = 1000 - n
changes = [500, 100, 50, 10, 5, 1]
res = 0
for i in changes:
    res += n // i
    n %= i
print(res)