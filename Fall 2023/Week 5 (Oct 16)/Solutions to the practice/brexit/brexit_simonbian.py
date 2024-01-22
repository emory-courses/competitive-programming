import sys








V,k,our,first = map(int,sys.stdin.readline().strip().split(' '))
AL = [[] for _ in range(V)]
mps = {}
qrs = []
for i in range(k):
    u,v = map(int,sys.stdin.readline().strip().split(' '))
    if u-1 not in mps:
        mps[u-1]=1
    else:
        mps[u-1]+=1
    if v-1 not in mps:
        mps[v-1]=1
    else:
        mps[v-1]+=1
    AL[u - 1].append(v - 1)
    AL[v - 1].append(u - 1)
graph = AL
mps2 = mps.copy()
from collections import deque
start = first-1
to_visit = deque()
dist = [float('inf')] * len(graph)
prec = [None] * len(graph)
pped = set()
dist[start] = 0
to_visit.appendleft(start)
away = [start]
while to_visit:  # an empty queue is considered False
    node = to_visit.pop()
    for neighbor in graph[node]:
        mps[neighbor]-=1
        if dist[neighbor] == float('inf') and mps[neighbor]<=0.5*mps2[neighbor]:
            dist[neighbor] = dist[node] + 1
            prec[neighbor] = node
            to_visit.appendleft(neighbor)
            away.append(neighbor)
if our-1 in away:
    print("leave")
else:
    print('stay')
