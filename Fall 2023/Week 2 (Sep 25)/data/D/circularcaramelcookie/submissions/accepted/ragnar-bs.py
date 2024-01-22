#!/usr/bin/env python3

from math import sqrt, floor

n = int(input()) + 1


def test(r):
    cnt = 0
    i = 0
    for i in range(1, int(r) + 1):
        cnt += int(sqrt(r * r - i * i))
        if 4 * cnt > n:
            break
    return 4 * cnt


l = 0
h = n
for _ in range(64):
    m = (l + h) / 2
    if test(m) < n:
        l = m
    else:
        h = m
print(l)
