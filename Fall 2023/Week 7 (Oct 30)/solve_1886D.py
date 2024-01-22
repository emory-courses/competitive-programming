from itertools import compress

def primes(n):
    """ Returns  a list of primes < n for n > 2 """
    sieve = bytearray([True]) * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = bytearray((n-i*i-1)//(2*i)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def factorization(n):
    """ Returns a list of the prime factorization of n """
    pf = []
    for p in primeslist:
      if p*p > n : break
      count = 0
      while not n % p:
        n //= p
        count += 1
      if count > 0: pf.append((p, count))
    if n > 1: pf.append((n, 1))
    return pf

def divisors(n):
    """ Returns an unsorted list of the divisors of n """
    divs = [1]
    for p, e in factorization(n):
        divs += [x*p**k for k in range(1,e+1) for x in divs]
    return divs

primeslist = primes(int(10**6**0.5)+1)
import sys
for test in range(int(sys.stdin.readline())):
    q = int(sys.stdin.readline())
    l = list(map(int,sys.stdin.readline().strip().split(' ')))
    mps = {}
    for i in l:
        fac = factorization(i)
        for v in fac:
            if v[0] not in mps:
                mps[v[0]] = v[1]
            else:
                mps[v[0]]+= v[1]
    b = True
    for x in mps.values():
        if x%q!=0:
            b = False
    if b:
        print("YES")
    else:
        print("NO")
