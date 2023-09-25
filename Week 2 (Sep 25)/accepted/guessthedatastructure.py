import heapq
import sys
while True:
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
            if a == 1:
                stack.append(b)
                queue.append(b)
                heapq.heappush(pq, -b)
            if a == 2:
                if isstack:
                    if not stack:  # Check if the stack is empty
                        isstack = False
                    else:
                        valstack = stack.pop()
                        isstack = b == valstack
                if isqueue:
                    if not queue:  # Check if the queue is empty
                        isqueue = False
                    else:
                        valqueue = queue.pop(0)
                        isqueue = b == valqueue
                if ispq:
                    if not pq:  # Check if the priority queue is empty
                        ispq = False
                    else:
                        valheapq = -heapq.heappop(pq)
                        ispq = b == valheapq

        sums = ispq + isqueue + isstack
        if sums > 1:
            print("not sure")
        elif sums == 0:
            print("impossible")
        else:
            if isstack:
                print("stack")
            elif isqueue:
                print("queue")
            elif ispq:
                print("priority queue")
    except:
        sys.exit(0)