import sys
n, m = map(int, input().split())
b = []
[ b.append(input()) for _ in range(n) ]

res = sys.maxsize

s_w = 'WB' * 4
s_b = 'BW' * 4

def s_diff(a, b):
    return sum(a[i] != b[i] for i in range(8))

for i in range(n - 7):
    for j in range(m - 7):
        odd = 0
        even = 0
        odd += sum(s_diff(b[m][j : j + 8], s_w) for m in range(i, i + 8) if m % 2 == 0)
        odd += sum(s_diff(b[m][j : j + 8], s_b) for m in range(i, i + 8) if m % 2 != 0) 
        even += sum(s_diff(b[m][j : j + 8], s_b) for m in range(i, i + 8) if m % 2 == 0)
        even += sum(s_diff(b[m][j : j + 8], s_w) for m in range(i, i + 8) if m % 2 != 0)
        res = min(res, odd, even)

print(res)