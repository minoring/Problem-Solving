import sys
input = sys.stdin.readline

n = int(input())

adj = []

for _ in range(n):
    adj.append(list(map(int, input().split())))

def dfs(v, visited):
    for e in range(n):
        if adj[v][e] == 1 and visited[e] == 0:
            visited[e] = 1
            dfs(e, visited)

    return visited

for i in range(n):
    print(' '.join(str(e) for e in dfs(i, [0] * n)))