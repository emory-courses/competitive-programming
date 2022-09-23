n = int(input())
a = [int(x) for x in input().split()]
a.sort()
print(' '.join(str(x) for x in a))