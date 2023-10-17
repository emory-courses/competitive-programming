import sys
V = 99
while V!=-1:
    V = int(sys.stdin.readline())
    if V==-1:
        break
    AM = [[0 for i in range(V)] for j in range(V)]
    for i in range(V):
        AM[i] = list(map(int, (sys.stdin.readline().strip().split())))

    if V==1:
        print(0)
    elif V==2:
        print('0 1')
    else:
        graph = [[] for i in range(V)]

        for i in range(V):
            for j in range(V):
                if AM[i][j]:
                    graph[i].append(j)

        for i in range(len(graph)):
            pted = False
            q = graph[i]
            for ii in q:
                for j in range(len(graph)):
                    if j!=i:
                        if i in graph[j] and ii in graph[j]:
                            pted = True
            if not pted:
                print(i,end=' ')
    print()
