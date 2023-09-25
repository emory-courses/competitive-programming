import sys, heapq
### Note: Copy right not by Simon. Please visit web for ownership.
heap = [(0, 0)]
current = [heap[0]]
indexes = {}
names = ['The clinic is empty']

next(sys.stdin)
for line in sys.stdin:
    command, *args = line.split()
    if command == '0':
        name, level = args
        index = indexes[name] = len(names)
        names.append(name)
        entry = -int(level), index
        current.append(entry)
        heapq.heappush(heap, entry)
    elif command == '1':
        name, increase = args
        index = indexes[name]
        old_level = current[index][0]
        entry = old_level - int(increase), index
        current[index] = entry
        heapq.heappush(heap, entry)
    elif command == '2':
        name, = args
        index = indexes[name]
        current[index] = None
    else:
        while heap[0] is not current[heap[0][1]]:
            heapq.heappop(heap)
        print(names[heap[0][1]])