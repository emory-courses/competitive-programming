input()
p = list(map(int, input().split()))
p.sort()
p = p[::-1]

print(max([h+1 for h in range(len(p)) if p[h] >= h+1]))
