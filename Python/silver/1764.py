# 집합을 활용해보자
a, b = map(int, input().split())
arr1 = set()
arr2 = set()
for i in range(a):
    c = input()
    arr1.add(c)
for i in range(b):
    c = input()
    arr2.add(c)
result = arr1 & arr2
result = sorted(result)
print(len(result))
for i in range(len(result)):
    print(result[i])