a = int(input())
for i in range(a):
    n, m = map(int, input().split())
    n1 = n
    m1 = m
    while m > 0:
        n, m = m, n % m
    print(int(n1 * m1 / n))