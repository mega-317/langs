n, m = map(int, input().split())
arr1 = []
arr2 = []

for i in range(n):
    a = input()
    arr1.append(a)
    
for i in range(m):
    b = input()
    arr2.append(b)

arr1 = sorted(arr1, key=len)

count = 0
for i in range(m):
    for j in range(n):
        if arr1[j] == arr2[i]:
            count += 1
        if len(arr1[j]) < len(arr2[i]):
            continue
print(count)