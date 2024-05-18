import sys
from collections import deque

a = int(input())

q = deque()

for i in range(a):
    b = list(map(int, sys.stdin.readline().split()))

    if b[0] == 1:
        q.appendleft(b[1])
    elif b[0] == 2:
        q.append(b[1])
    elif b[0] == 3:
        if not q:
            print(-1)
        else:
            print(q.popleft())
    elif b[0] == 4:
        if not q:
            print(-1)
        else:
            print(q.pop())
    elif b[0] == 5:
        print(len(q))
    elif b[0] == 6:
        if not q:
            print(1)
        else:
            print(0)
    elif b[0] == 7:
        if not q:
            print(-1)
        else:
            print(q[0])
    elif b[0] == 8:
        if not q:
            print(-1)
        else:
            print(q[-1])
