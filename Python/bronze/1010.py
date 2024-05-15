import math

a = int(input())
for i in range(a):
    b, c = map(int, input().split())
    c1 = math.factorial(c)
    b1 = math.factorial(b)
    b2 = math.factorial(c-b)
    print(int(c1 / (b1 * b2)))