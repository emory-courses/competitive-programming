#!/usr/bin/env python3

from math import sqrt, floor, ceil, pi

n = int(input()) // 4 + 1

# area >= 4*n
# pi*r^2 >= 4*n
# r >= sqrt(4*n/pi)
ll = int(4 * n / pi)
hh = int((sqrt(ll) + 1) ** 2)
cnt = 0

rs = [ll]
for x in range(1, int(sqrt(ll)) + 3):
    y = int(sqrt(ll - x * x)) if x * x <= ll else 0
    cnt += y
    # y: first value that increases the number of squares
    # x*x+y*y>l*l
    y += 1
    while x * x + y * y <= hh:
        rs.append(x * x + y * y)
        y += 1
rs.sort()
print(sqrt(rs[n - cnt]))
