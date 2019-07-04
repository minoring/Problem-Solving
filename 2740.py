N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

_, K = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(M)]

C = [[sum(A[i][k] * B[k][j] for k in range(M)) for j in range(K)] for i in range(N)]

for i in range(N):
    print(" ".join(str(x) for x in C[i]))
