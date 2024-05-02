a = int(input())
arr = [0]*10000
for i in  range(a):
    b = int(input())
    arr[b-1] += 1
for i in range(10000):
    while arr[i] != 0:
        print(i+1)
        arr[i] -= 1