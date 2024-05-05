import math

def prime():
    n = 1000000
    array = [True] * (n + 1)
    
    for i in range(2, int(math.sqrt(n)) + 1):
        if array[i] == True:
            j = 2
            while i * j <= n:
                array[i * j] = False
                j += 1
    return array

arr = prime()
a = int(input())
for i in range(a):
    count = 0
    b = int(input())
    for i in range(2, b // 2 + 1):
        if arr[i] and arr[b - i]:
            count += 1
    print(count)