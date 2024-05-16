a = int(input())

queue = []

for i in range(a):
    queue.append(i+1)

front = 0
rear = len(queue) - 1

if front == rear:
    print(1)
else:
    while front <= rear:
        front += 1
        queue.append(queue[front])
        rear += 1
        front += 1
        if front == rear:
            break
    print(queue[front])