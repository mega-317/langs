arr = []

while True:
    b = input()
    if b == '.':
        break
    else:
        arr.append(b)

for i in range(len(arr)):
    arr1 = []
    index = 0
    arr1.append(-1)
    res = 1
    for j in range(len(arr[i])):
        if arr[i][j] == '(':
            arr1.append('(')
            index += 1
        elif arr[i][j] == '[':
            arr1.append('[')
            index += 1
        elif arr[i][j] == ')':
            if arr1[index] == '(':
                arr1.pop()
                index -= 1
            else:
                res = 0
        elif arr[i][j] == ']':
            if arr1[index] == '[':
                arr1.pop()
                index -= 1
            else:
                res = 0
    if arr1[index] != -1:
        res = 0
    
    if res:
        print("yes")
    else:
        print("no")