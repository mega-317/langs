a = int(input())
arr = []
for i in range(a):
    b = int(input())
    if b == 0:
        arr.pop()
    else:
        arr.append(b)
print(sum(arr))