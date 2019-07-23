n = int(input())
if n % 2 == 0:
    print('I LOVE CBNU')
else:
    print('*' * n)
    print(' ' * (n // 2) + '*')
    for i in range(1, n // 2 + 1):
        print(' ' * (n // 2 - i) + '*' + ' ' * (2 * i - 1) + '*')