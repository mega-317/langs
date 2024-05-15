import sys

a = int(input())
b = []
queue = [0] * 2000000
front = -1
rear = -1
for i in range(a):
    b = list(map(str, sys.stdin.readline().split()))
    if b[0] == 'push':
        val = int(b[1])
        if rear == -1:
            front += 1
            rear += 1
            queue[rear] = val
        else:
            rear += 1
            queue[rear] = val  
    elif b[0] == 'pop':
        if front == -1 or front > rear:
            print(-1)
        else:
            print(queue[front])
            front += 1
    elif b[0] == 'size':
        if front == -1 or front > rear:
            print(0)
        else:
            print((rear - front) + 1)
    elif b[0] == 'empty':
        if front == -1 or front > rear:
            print(1)
        else:
            print(0)
    elif b[0] == 'front':
        if front == -1 or front > rear:
            print(-1)
        else:
            print(queue[front])
    elif b[0] == 'back':
        if front == -1 or front > rear:
            print(-1)
        else:
            print(queue[rear])