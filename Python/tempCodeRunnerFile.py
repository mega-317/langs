while True:
    a, b, c = map(int, input().split())
    
    if a==0 and b==0 and c==0:
        break
    
    max = a
    min1 = b
    min2 = c
    if (b > max):
        max = b
        min1 = a
    if (c > max):
        max = c
        min1 = b
        min2 = a
    
    print(max, min1, min2)
    
    if max >= (min1 + min2):
        print('Invalid')
    elif max != min1 and max != min2 and min1 != min2:
        print('Scalene')
    elif max == min1 and min1 == min2:
        print('Equilateral')
    else:
        print('Isosceles')