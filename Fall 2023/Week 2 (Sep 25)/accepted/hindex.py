import sys
nums = int(sys.stdin.readline())
l ={}
for i in range(nums):
    q = int(sys.stdin.readline())
    if q in l:
        l[q]+=1
    else:
        l[q]=1

ars = list(l.keys())
ars.sort()
i = len(ars)-1
curmax = 0
while i>=0:
    if ars[i]<=nums:
        break
    else:
        curmax += l[ars[i]]
      #  print("curmax...",curmax)
    i-=1

if curmax>=nums:
    print(nums)
else:
    i = nums
    while i>=0:
        if curmax>=i+1:
            break
        else:
            if i in l:
                curmax = curmax + l[i]
        i = i-1
       # print(curmax,"curmax",i+1,'Index')
    print(i+1)