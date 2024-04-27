a, b = map(int, input().split())
arr = {}

for i in range(a):
    name = input()
    arr[i+1] = name

d = {value : key for key, value in arr.items()}

for i in range(b):
    c = input()
    if c.isalpha():
        print(d.get(c))
    else:
        print(arr.get(int(c)))
