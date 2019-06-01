z = o = t = 0
for _ in range(int(input())):
    n = int(input())
    z, o, t = max(z, o, t), z + n, o + n
print(max(z, o, t))