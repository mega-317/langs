a = int(input())

b = list(map(int, input().split()))
q = []
res = []
count = 0

for i in range(a):
    q.append(b[i])

index = 0

while True:
    res.append(index + 1)
    count += 1
    if count == a:
        break
    next = q[index]
    q[index] = 0
    
    if next > 0:
        # 시계 방향으로 이동하는 경우
        # a와 인덱스가 '같을' 경우 첫 요소로 이동시켜줘야 한다
        for j in range(next):
            index += 1
            if index >= a:
                index %= a
            while q[index] == 0:
                index += 1
                if index >= a:
                    index %= a
    else:
        # 반시계 방향으로 이동하는 경우
        # 인덱스가 0 보다 '작을' 경우 맨 끝 요소로 이동시켜줘야 한다
        for j in range(-1 * next):
            index -= 1
            if index < 0:
                index += a
            while q[index] == 0:
                index -= 1
                if index < 0:
                    index += a
                    
# 근본적으로 배열의 개수와 배열의 끝 인덱스가 다르다는 것을 항상 고려해야 한다
# 특히 원형 큐의 경우!!!
            
for i in range(len(res)):
    print(res[i], end=" ")