a = int(input())
arr = list(map(int, input().split()))
resultPlus = [0 for j in range(10000001)]
resultMinus = [0 for k in range(10000001)]
for i in range(a):
    b = arr[i]
    if b >= 0:
        resultPlus[b] = 1
    else:
        resultMinus[-b] = 1

c = int(input())
arr1 = list(map(int, input().split())) 
for i in range(c):
    if arr1[i] >= 0:
        print(resultPlus[arr1[i]], end=" ")
    else:
        print(resultMinus[-arr1[i]], end=" ")