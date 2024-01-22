import heapq

def dijkstra(graph, weights, start):
    queue = [(0, start)]
    visited = set()
    distance = {node: float('infinity') for node in graph}
    distance[start] = 1
    while queue:
        (dist, current) = heapq.heappop(queue)
        if current in visited:
            continue
        visited.add(current)
        for neighbor in graph[current]:
            old_distance = distance[neighbor]
            new_distance = distance[current] / weights[current][neighbor]
            if new_distance < old_distance:
                distance[neighbor] = new_distance
                heapq.heappush(queue, (new_distance, neighbor))
    return distance
import sys
a,b = map(int,sys.stdin.readline().split(' '))
while a!=0 and b!=0:
    graph = {i: [] for i in range(a)}
    weights = {i: {} for i in range(a)}
    for i in range(b):
        s,t,w = map(float,sys.stdin.readline().split(' '))
        s = int(s)
        t = int(t)
        graph[s].append(t)
        weights[s][t] = w
        graph[t].append(s)
        weights[t][s] = w
    for i in range(a):
        graph[i].append(i)
        weights[i][i] = 1
        graph[i].append(i)
        weights[i][i] = 1
    a =  1/float(dijkstra(graph,weights,0)[a-1])
    print('%.4f' % a)
    a, b = map(int, sys.stdin.readline().split(' ')
