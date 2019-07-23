n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)] 

res = 0
for n in coins[::-1]:
    res += k // n
    k = k % n
print(res)