n = int(input())
a = sorted(int(input()) for _ in range(n))
print(max((n - i) * a[i] for i in range(n)))