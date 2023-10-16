from collections import defaultdict
import sys
V = int(sys.stdin.readline())
AL = defaultdict(list) #initalize AL
for i in range(V):
    line = list(map(int, (sys.stdin.readline().strip().split())))
    total_neighbours = int(line[0])
    for j in range(1, len(line), 2):
        v, w = int(line[j]), int(line[j + 1])
        AL[i].append((v - 1, w))
print(AL)

'''
6
2 2 10 5 100
3 1 10 3 7 5 8
2 2 7 4 9
3 3 9 5 20 6 5
3 1 100 2 8 4 20
1 4 5
THe first line: There are [2] vertices connected.
The first is naturally numbered 2, computationally labeled 1, has weight 10 (optionally)
The second is naturally numbered 5, coomputationally labeled 4, has weight 100
0: [(1, 10), (4, 100)

'''
