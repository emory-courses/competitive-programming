import sys
a,b = map(int,sys.stdin.readline().strip().split(' '))
c = list(map(int,sys.stdin.readline().strip().split(' ')))
c.sort()
print(sum(c[-b:])+sum(c))
