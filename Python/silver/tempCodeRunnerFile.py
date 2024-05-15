a = int(input())

arr = list(map(int, input().split()))
b = sorted(arr.copy())
stack = []
arr1 = []

while len(arr) != 0:
    min1 = min(arr)
    if arr[0] != min1:
        stack.append(arr[0])
        arr.pop(0)
    else:
        arr1.append(arr[0])
        arr.pop(0)
        
while len(stack) != 0:
    arr1.append(stack.pop())
    
if b != arr1:
    print("Sad")
else:
    print("Nice")