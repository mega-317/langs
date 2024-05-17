a, b = map(int, input().split())

q = [i for i in range(1, a+1)]
res = []

index = b - 1

while len(q) != 0:
    if index >= len(q):
        index %= len(q)
    res.append(q.pop(index))
    index += (b - 1)
    
print("<", end="")
for i in range(len(res) - 1):
    print(res[i], end="")
    print(", ", end="")
print(res[len(res) - 1], end="")
print(">")