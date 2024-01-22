import sys
nums = int(sys.stdin.readline().strip())
a = []
names = {}
for i in range(nums):
    q = sys.stdin.readline().strip().split(' ')
    if q[0] not in names:
        names[q[0]]={}
    for word in q[1:]:
        if word not in names[q[0]]:
            names[q[0]][word] = 1
        else:
            names[q[0]][word] += 1
l = list(names.keys())
base = set(names[l[0]].keys())
for i in l[1:]:
    base = base.intersection(set(names[i].keys()))
counts = {}
for i in base:
    for j in l:
        if i not in counts:
            counts[i]=names[j][i]
        else:
            counts[i] += names[j][i]
c = sorted(counts.items(),key=lambda x:x[1],reverse=True)
if c:
    for i in c:
        print(i[0])
else:
    print('ALL CLEAR')