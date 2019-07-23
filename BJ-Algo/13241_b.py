import math
a, b = map(int, input().split())
print(a * b//math.gcd(a, b))

#  a, b의 최대공약수 G = gcd(a, b)에서 아래 식을 만족하는 정수 x와 y 가 존재한다.
# a = Gx, b = Gy (x 와 y 는 서로소 관계)
# a 와 b 의 합집합은 G, x, y 이고, 이 세수를 곱한 G * x * y는 최소공배수가 된다.
# 이때 a * b = G * G * x * y 이다.
# 따라서 최소공배수 lcm(a, b) = G * x * y = a * b / gcd(a, b) 이다.