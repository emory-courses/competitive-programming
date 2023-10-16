import sys
V = int(sys.stdin.readline())
AM = [[0 for i in range(V)] for j in range(V)]
for i in range(V):
    AM[i] = list(map(int, (sys.stdin.readline().strip().split())))
print(AM)
