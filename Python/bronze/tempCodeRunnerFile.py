import sys

a = int(input())
for i in range(a):
    n, m = map(int, sys.stdin.readline().split())
    sum = n
    for i in range(m):
        sum = (sum * n) % 10
    if sum == 0:
        print(10)
    else:
        print(sum)