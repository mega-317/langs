b, a = map(int, input().split())

array = [[0 for col in range(a)] for row in range(b)]
for i in range(b):
    str = input()
    array[i] = list(str)

re_list = []

a -= 1
b -= 1
x = 0
while x+7 <= a:
    y = 0
    while y+7 <= b:
        
        re = 0
        re1 = 0
        
        y1 = y
        for i in range(8):
            x1 = x
            for j in range(8):
                if i%2 == 0 and j%2 == 0:
                    if array[y1][x1] != 'B':
                        re += 1
                if i%2 == 0 and j%2 == 1:
                    if array[y1][x1] != 'W':
                        re += 1
                if i%2 == 1 and j%2 == 0:
                    if array[y1][x1] != 'W':
                        re += 1
                if i%2 == 1 and j%2 == 1:
                    if array[y1][x1] != 'B':
                        re += 1
                x1 += 1
            y1 += 1

        y1 = y
        for i in range(8):
            x1 = x
            for j in range(8):
                if i%2 == 0 and j%2 == 0:
                    if array[y1][x1] != 'W':
                        re1 += 1
                if i%2 == 0 and j%2 == 1:
                    if array[y1][x1] != 'B':
                        re1 += 1
                if i%2 == 1 and j%2 == 0:
                    if array[y1][x1] != 'B':
                        re1 += 1
                if i%2 == 1 and j%2 == 1:
                    if array[y1][x1] != 'W':
                        re1 += 1
                x1 += 1
            y1 += 1
            
        if re > re1:
            re_list.append(re1)
        else:
            re_list.append(re)
        
        
        y += 1
    x += 1
print(min(re_list))