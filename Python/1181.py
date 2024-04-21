a = int(input())
arr = []
for i in range(a):
    arr.append(input())
arr.sort(key=len) # i. 우선 문자열의 크기를 기준으로 정렬
arr1 = []
i = 0
while i < a-1: # 문자열의 길이가 같은 것들은 arr1 배열에 구간을 삽입
    if len(arr[i]) == len(arr[i+1]):
        arr1.append(i)
        j = i + 1
        while len(arr[i]) == len(arr[j]):
            if j + 1 < a:
                j += 1
            else:
                break
            
        if j + 1 != a:
            j -= 1
        arr1.append(j)
        i = j
    else:
        i += 1
i = 0

while i < len(arr1): # 문자열이 동일한 구간을 부분 배열 arr2에 삽입 후 정렬시키고 arr에 다시 삽입
    n = arr1[i]
    m = arr1[i + 1]
    arr2 = []
    while n <= m:
        arr2.append(arr[n])
        n += 1
    arr2.sort()
    index = 0
    n = arr1[i]
    m = arr1[i + 1]
    while n <= m:
        arr[n] = arr2[index]
        index += 1
        n += 1
    i += 2
for i in range(len(arr)): # 중복 제거
    j = i + 1
    if j < len(arr):
        while arr[i] == arr[j]:
            arr.pop(j)
            j = i
            if j + 1 < len(arr):
                j += 1
            else:
                break
for i in range(len(arr)):
    print(arr[i])