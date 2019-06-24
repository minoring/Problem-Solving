e, s, m = map(int, input().split())
x = 0
while not(x % 15 == e - 1 and x % 28 == s - 1 and x % 19 == m - 1):
    x += 1
print(x + 1)