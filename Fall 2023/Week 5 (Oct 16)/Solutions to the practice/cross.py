# snip}
import sys

from heapq import heappop, heappush

# snip{


def dijkstra(graph, weight, source, target):
    n = len(graph)
    dist = [float('inf')] * n
    dist[source] = 0
    heap = [(0,source)]
    while heap:
        dist_node, node = heappop(heap)       # Closest node from source
        if (dist_node != dist[node]): continue
        for neighbor in graph[node]:
            dist_neighbor = dist_node + weight[node][neighbor]
            if dist_neighbor < dist[neighbor]:
                dist[neighbor] = dist_neighbor
                heappush(heap, (dist_neighbor, neighbor))
    return dist
# snip}
nmsq = sys.stdin.readline()

n, start,end = map(int, nmsq.split())
q = []
for i in range(n):
    q.append(i)
#print(q)
# Initialize the graph and weight matrix as dictionaries
graph = {i: [] for i in range(n)}
weights = {i: {} for i in range(n)}

for _ in range(n):
    w = list(map(int, sys.stdin.readline().split()))
    v = q.copy()
    v.remove(_)
    graph[_]=v
    weights[_] = w  # Store weights as a dictionary for each node

#print(graph,weights)
source = start

dist = dijkstra(graph, weights, source,end)
print(dist[end])
