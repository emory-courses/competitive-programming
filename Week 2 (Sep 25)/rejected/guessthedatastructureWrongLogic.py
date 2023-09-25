import heapq
import sys
while True:
    printed = False
    try:
        stack = []
        queue = []
        pq = []
        isstack = True
        isqueue = True
        ispq = True
        q = int(sys.stdin.readline().strip())
        for i in range(q):
            a,b = map(int,sys.stdin.readline().strip().split(' '))
            if a==1:
                stack.append(b)
                queue.append(b)
                heapq.heappush(pq,-b)
            if a==2:
                if isstack:
                    valstack = stack.pop(0)
                    isstack = b == valstack
                if isqueue:
                    valqueue = queue.pop(-1)
                    isqueue = b == valqueue
                if ispq:
                    valheapq = -heapq.heappop(pq)
                    ispq = b== valheapq

        sums = ispq+isqueue+isstack
        if sums>1:
            print("not sure")
        if sums==0:
            print("impossible")
        if sums==1:
            if ispq:
                print("stack")
            if isstack:
                print("queue")
            if ispq:
                print("priority queue")
        printed = True
    except:
        if not printed:
            print("impossible")
        sys.exit(0)