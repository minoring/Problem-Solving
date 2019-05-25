m, n = map(int, input().split())
s = [*range(n + 1)]
for i in s[2:]:
    if s[i]:
        s[2*i: :i] = [0] * (n // i - 1)
        if i >= m:
            print(i)