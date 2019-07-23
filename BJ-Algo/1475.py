from collections import Counter
import math
num = map(int, [n for n in input()])
cnt = Counter(num)

if 6 not in cnt:
    cnt[6] = 0
if 9 not in cnt:
    cnt[9] = 0

avg = math.ceil((cnt[6] + cnt[9]) / 2)
cnt[6] = avg
cnt[9] = avg

print(max(cnt.values()))