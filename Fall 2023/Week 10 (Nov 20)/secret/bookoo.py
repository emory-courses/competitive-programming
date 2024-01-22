
def nxt(q):
    if q>=0 and q<14:
        return 15
    if q>=15 and q<30:
        return 30
    if q>=30 and q<45:
        return 45
    return 0
import sys
a = sys.stdin.readline().strip()
query = int(sys.stdin.readline().strip())
#a = '02:36'
#query = 1
a = a.split(':')

hr,mn = int(a[0]),int(a[1])

exs = 0
flg = True
if mn in [15,30,45]:
    exs+=1
while exs<query:
    #print('begin',exs, hr, mn)
    if mn==0 and flg:
        flg = False
        exs+=hr
        # mn = nxt(mn)
        #print('if==', exs, hr, mn)
    else:

        mn = nxt(mn)
        if mn==0:
            flg = True
            if hr>=12:
                hr = 1
            else:
                hr = hr+1
            exs-=1
        exs+=1
        #print('else==', exs, hr, mn)
print(str(hr).zfill(2)+":"+str(mn).zfill(2))
