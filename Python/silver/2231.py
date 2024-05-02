a = int(input())
result = []
for i in range(a):
    i_list = map(int, str(i))
    
    if (i + sum(i_list)) == a:
        result.append(i)

if len(result) == 0:
    print(0)
else:
    print(min(result))