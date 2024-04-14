
a, b, c = map(int, input().split())

max = a
min1 = b
min2 = c
if b > max:
    max = b
    min1 = a
if c > max:
    max = c
    min1 = b
    min2 = a
    
if max >= (min1 + min2):
    max = min1 + min2 - 1

print(max + min1 + min2)
    
