import sys

l ={}
for i in range(int(sys.stdin.readline())):
    q = int(sys.stdin.readline())
    if q in l:
        l[q]+=1
    else:
        l[q]=1
v = list(l.keys())
v.sort(reverse=True)

cur = 0
last = 0
noted = 0
flg = False
for i in v:
    cur += l[i]
    #print(cur,i)
    if cur>=i and (not flg):
        noted = i
        flg = True
    else:
        flg = False
print(noted)