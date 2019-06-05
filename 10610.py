n = sorted(input())
print(-1 if sum(map(int, n)) % 3 + int(n[0]) else ''.join(n)[::-1])