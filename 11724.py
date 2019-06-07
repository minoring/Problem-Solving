import sys
input = sys.stdin.readline

V, E = map(int, input().split())
parent = [i for i in range(0, V + 1)]

def find(n):
    if parent[n] != n:
        parent[n] = find(parent[n])
    return parent[n]

def union(n1, n2):
    parent[find(n2)] = find(n1)

for _ in range(E):
    v, e = map(int, input().split())
    union(v, e)

print(len(set([find(i) for i in range(1, V + 1)])))