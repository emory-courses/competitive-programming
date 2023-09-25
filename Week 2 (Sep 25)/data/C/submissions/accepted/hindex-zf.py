#!/usr/bin/python3

p = [int(input()) for _ in range(int(input()))]
p.sort()
p = p[::-1]

print(max([0] + [h+1 for h in range(len(p)) if p[h] >= h+1]))
