n, m = map(int, input().split())
arr1 = set()
arr2 = []

for i in range(n):
    a = input()
    arr1.add(a)
    
for i in range(m):
    b = input()
    arr2.append(b)

count = 0
for element in arr2:
    if element in arr1:
        count += 1
print(count)