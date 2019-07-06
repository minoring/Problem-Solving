def gcd(a, b):
    a, b = max(a, b), min(a, b)
    if b == 0:
        return a
    return gcd(b, a % b)


n, m = map(int, input().split(":"))
g = gcd(n, m)
print(str(n // g) + ":" + str(m // g))
