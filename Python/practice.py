
a, b = map(int, input().split())

array = []

for i in range(a):
    if a % (i+1) == 0:
        array.append(i+1)

if b > len(array):
    print(0)
else:
    print(array[b-1])
