import sys

a = int(input())
for i in range(a):
    n, m = map(int, sys.stdin.readline().split())
    sum = n
    if m == 1:
        sum %= 10
    else:
        while m-1 > 0:
            sum = (sum * n) % 10
            m -= 1
    if sum == 0:
        print(10)
    else:
        print(sum)