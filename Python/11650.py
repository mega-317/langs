a = int(input())

arr = []

for i in range(a):
    arr1 = list(map(int, input().split()))
    arr.append(list(arr1))

for i in range(a):
    temp = arr[i][0]
    arr[i][0] = arr[i][1]
    arr[i][1] = temp

arr = sorted(arr)

for i in range(a):
    temp = arr[i][0]
    arr[i][0] = arr[i][1]
    arr[i][1] = temp
    
for i in range(a):
    print(arr[i][0], arr[i][1])