n, r, c = map(int, input().split())


def z(n, r, c):
    if n == 1:
        return r * 2 + c

    if r >= 2 ** (n - 1):
        r -= 2 ** (n - 1)
        if c >= 2 ** (n - 1):
            c -= 2 ** (n - 1)
            quadrant = 3
        else:
            quadrant = 2
    else:
        if c >= 2 ** (n - 1):
            c -= 2 ** (n - 1)
            quadrant = 1
        else:
            quadrant = 0

    return z(n - 1, r, c) + (2 ** (2 * (n - 1))) * quadrant


print(z(n, r, c))
