n = int(input())
for i in range(-n + 1, n):
    print(' ' * abs(i) + '*' * ((2 * n - 1) - (2 * abs(i))))