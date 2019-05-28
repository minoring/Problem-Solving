_ = input()
l = list(map(int, input().split()))
l.sort()

wait = 0
res = 0
for n in l:
    wait += n 
    res += wait
print(res)