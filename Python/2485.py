def A(a, b):
    if a > b:
        while b > 0:
            [a, b] = [b, a%b]
        return a
    else:
        while a > 0:
            [b, a] = [a, b%a]
        return b

a = int(input())
b = []
for i in range(a):
    tree = int(input())
    b.append(tree)

dis = set()
j = a-1
while j > 0:
    c = b[j] - b[j-1]
    dis.add(c)
    j -= 1
arr = list(dis)
d = arr[0]
for i in range(len(arr)):
    d = A(d, arr[i])
    if d == 1:
        break

newTree = d
firstTree = b[0]
lastTree = b[len(b)-1]

print((int((lastTree - firstTree) / newTree) + 1) - len(b))