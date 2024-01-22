import heapq
import sys

cats = {}
a = int(sys.stdin.readline())
for i in range(a):
    query = sys.stdin.readline().strip()
    if query[0]=='0':
        op,nm,vl = query.split(' ')
        cats[nm]=int(vl)
    if query[0]=="1":
        op, nm, vl = query.split(' ')
        cats[nm]=cats[nm]+int(vl)
    if query[0]=="2":
        op, nm = query.split(' ')
        cats.pop(nm)
    if query[0]=="3":
        vls = list(cats.values())
        if len(vls)>=1:
            ind = vls.index(max(vls))
            nms = list(cats.keys())
            print(nms[ind])
        else:
            print("The clinic is empty")
    #print(cats.values())