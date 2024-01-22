def topological_order_dfs(graph,input):
    """Topological sorting by depth first search

    :param graph: directed graph in listlist format, cannot be listdict
    :returns: list of vertices in order
    :complexity: `O(|V|+|E|)`
    """
    n = len(graph)
    order = []
    times_seen = [-1] * n
    start = input
    if times_seen[start] == -1:
        times_seen[start] = 0
        to_visit = [start]
        while to_visit:
            node = to_visit[-1]
            children = graph[node]
            if times_seen[node] == len(children):
                to_visit.pop()
                order.append(node)
            else:
                child = children[times_seen[node]]
                times_seen[node] += 1
                if times_seen[child] == -1:
                    times_seen[child] = 0
                    to_visit.append(child)
    return order[::-1]

import sys
V = int(5*100000+50)
AL = [[] for _ in range(V)]
mps ={}
revmps = {}
nat= 0
for u in range(int(sys.stdin.readline())):
    tkn = list(map(str, sys.stdin.readline().strip().split()))
    tkn[0]=tkn[0].replace(':','')
    for i in tkn:
        if i not in mps:
            mps[i]=nat
            revmps[nat]=i
            nat+=1
    for i in range(1,len(tkn)):
        AL[mps[tkn[i]]].append(mps[tkn[0]])
#print(AL)
#print(mps)
#print(revmps)
#inputs()
seen = [False]*len(list(mps.values()))
query= sys.stdin.readline().strip()
ret = topological_order_dfs(AL,mps[query])
for i in ret:
    print(revmps[i])
#print(seen)
