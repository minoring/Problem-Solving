N = 100001
is_prime = [False, False] + [True] * N

for i in range(2, int(N ** 0.5) + 1):
    if is_prime[i] == True:
        for j in range(i + i, N + 1, i):
            is_prime[j] = False

primes = []
for i in range(N):
    if is_prime[i] == True:
        primes.append(i)

for _ in range(int(input())):
    n = int(input())
    for p in primes:
        divided_count = 0
        while n % p == 0:
            divided_count += 1
            n //= p
        if divided_count != 0:
            print(p, divided_count)

        if n == 1:
            break
