import itertools
import sys
n = int(sys.stdin.readline().strip())
tst = []
ff = 1


def check(comb, three):
    if three[0] in comb and three[1] in comb:
        return False
    if three[2] in comb and three[1] in comb:
        return False
    if three[0] in comb and three[2] in comb:
        return False
    return True


def more_check(comb, lst):
    for three in lst:
        if not check(comb, three):
            return False
    return True


def gen_list(s, pos):
    l = []
    for q in range(1, 6):
        for i in (itertools.combinations(s, q)):
            if more_check(i + tuple(tst[0][pos]), tst):
                l.append(i)
            pass
    return l


def remove_letters(s, tup):
    q = s.copy()
    for i in tup:
        q.remove(i)
    return q


for q in range(n):
    tst.append(sys.stdin.readline().strip().replace("\n",''))
    x = tst[-1]
    if x[0]==x[1] or x[2]==x[1] or x[0]==x[2]:
        ff =0


def eval(d1,d2,d3):
  #  print(d1,d2,d3)
    for t in tst[1:]:
        v1 = 0
        v2 = 0
        v3 = 0
        for letter in t:
            if letter in d1 or letter==tst[0][0]:
                v1 += 1
            if letter in d2 or letter==tst[0][1]:
                v2 += 1
            if letter in d3 or letter==tst[0][2]:
                v3 += 1
     #   print(v1,v2,v3)
        if not (v1==1 and v2==1 and v3==1):
            return False
    return True

if ff:
    #print(tst)
    s = list(set(list(''.join(tst[0:]))))
    #print(s)
    ori = (len(s))
    if ori>=19:
        ff = 0
    else:
        s.remove(tst[0][0])
        s.remove(tst[0][1])
        s.remove(tst[0][2])
        #print(s)
        d1 = [tst[0][0]]
        d2 = [tst[0][1]]
        d3 = [tst[0][2]]
        l = gen_list(s,0)[::-1]
        flag = False
        for i in l:
            b = remove_letters(s,i)
            sec = gen_list(b,1)[::-1]
            if flag:
                break
            for j in sec:
                vals = remove_letters(b,j)
                third = gen_list(vals,2)[::-1]
                if flag:
                    break
                for t in third:
                    #print(len(i)+len(j)+len(t))
                    if len(i)+len(j)+len(t)==len(s):
                       # print(i, j, t)
                        if eval(i,j,t):
                            flag = True
                            #print(i,j,t)
                            m1 = i
                            m2 = j
                            m3 = t
                            break
       # print(m1,m2,m3)
        if not flag:
            ff=0
        else:
            for iii in m1:
                d1.append(iii)
                #s.remove(ii)
            for jjj in m2:
                d2.append(jjj)
                #s.remove(jj)
            for ttt in m3:
                d3.append(ttt)
                #s.remove(tt)
          #  print(d1,d2,d3)

            extra = list('abcdefghijklmnopqrstuvwxyz')
            ex = []
            for i in extra:
                if i not in d1 and i not in d2 and i not in d3:
                    ex.append(i)
            #print(d1,d2,d3)
            #print(ex)
            for d in [d1,d2,d3]:
                if len(d)<6:
                    need = 6-len(d)
                    for p in range(need):
                        d.append(ex[0])
                        ex.remove(ex[0])
            #final test:

            print(''.join(d1),''.join(d2),''.join(d3))
if not ff:
    print(0)
