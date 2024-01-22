#!/usr/bin/env python3
s, l, h = int(input()) + 1, 0, 1e5
while abs(l - h) / h > 1e-15:
    r = (l + h) / 2
    if 4 * sum(int((r * r - x * x) ** 0.5) for x in range(1, int(r) + 1)) < s: l = r
    else: h = r
print(r)
