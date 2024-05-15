import math

a, b = map(int, input().split())

a1 = math.factorial(a)
c1 = math.factorial(a - b)
b1 = math.factorial(b)

print(int(a1 / (c1 * b1)))
