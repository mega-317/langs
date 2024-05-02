a = int(input())
b = {}
for i in range(a):
    name, state = map(str, input().split())
    if state == 'enter':
        b[name] = 1
    else:
        b[name] = 0
result = []
for key, value in b.items():
    if value == 1:
        result.append(key)
result = reversed(sorted(result))
result = list(result)
for i in result:
    print(i)