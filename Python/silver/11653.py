x,y,w,h = map(int, input().split())

if x > (w/2):
    minx = w - x
else:
    minx = x
if y > (h/2):
    miny = h - y
else:
    miny = y
    
if (minx > miny):
    print(miny)
else:
    print(minx)