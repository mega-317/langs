def binary_search(arr, target):
    first, last = 0, len(arr) - 1
    while first <= last:
        mid = (first + last) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            first = mid + 1
        else:
            last = mid - 1
    return False

a = int(input())
arr = list(map(int, input().split()))

b = int(input())
arr1 = list(map(int, input().split()))

arr.sort()

for i in range(b):
    result = binary_search(arr, arr1[i])
    print(1 if result else 0)