import sys
E = int(sys.stdin.readline())
edge_list = []
for i in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    edge_list.append((w, u, v))
import heapq
heapq.heapify(edge_list)
# edges sorted by weight (smallest->largest)
for i in range(E):
    edge = heapq.heappop(edge_list)
    print('weight: {:d} ({:d}-{:d})'.format(edge[0], edge[1], edge[2]));

