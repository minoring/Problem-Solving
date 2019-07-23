coords = []
for _ in range(int(input())):
    x, y = map(int, input().split())
    coords.append((x, y))

for i in sorted(coords, key=lambda e: (e[0], e[1])):
    print(i[0], i[1])