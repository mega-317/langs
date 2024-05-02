a = input()
lenA = len(a)
res = []
k = 1
for i in range(lenA):
    j = 0
    while j + k <= lenA:
        res.append(a[j:j+k])
        j += 1
    k += 1
result = set(res)
print(len(result))