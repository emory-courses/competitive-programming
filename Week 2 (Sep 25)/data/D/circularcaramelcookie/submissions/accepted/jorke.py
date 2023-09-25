#!/usr/bin/env python3
import math
s = int(input())//4+1
r = (s*4/math.pi)**.5
tot = 0
border = []
x,y = 0,int(r)
while y>=0:
    border.append((x+1)**2 + (y+1)**2)
    if (x+1)**2 + y**2 >= r**2:
        y -= 1
    else:
        tot += y
        x += 1
border.sort()
print(border[s-tot-1]**.5)
