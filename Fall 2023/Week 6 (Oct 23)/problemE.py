import sys
a = sys.stdin.readline().strip()
a = a[::-1]
i = 0
 
v = 0
while i<=len(a)-1:
    if a[i]=='O':
        v+=pow(2,i,10**9+7)
    i+=1
print(v%(10**9+7))
 
