import random, sys, math

caseno = dict()

PROBID = "hindex"

MAXN = 100000
MAXC = 1000000000

# The first argument is a short string describing the "type" of data
# (eg. sample, hand, random), the rest have the test case data.
#
# This will generate the file in the data directory, putting type "sample" in
# sample and the rest in secret.
#
# Subsequent calls with the same type will increase the number following the
# type. Example: consecutive calls with type=="random" will create files
# PROBID-random-01.in, PROBID-random-02.in, ... in ../data/secret
def genfile(tp, c):
    global caseno

    caseno[tp] = caseno.get(tp, 0)+1

    #path = "."
    path = "../data/{0}".format("sample" if tp == "sample" else "secret")
    filename = "{0}/{1}-{2}-{3:02d}.in".format(path, PROBID, tp, caseno[tp])

    outfile = open(filename, "w")

    #####################################################
    # validate data, raise an error if bad
    #

    def check_range(a, lo, hi):
        if type(a) != int or a < lo or a > hi:
            raise ValueError("Bad int or range", a, lo, hi)
    check_range(len(c), 1, MAXN)
    if type(c) != list:
        raise ValueError("Not a list")
    for x in c:
        check_range(x, 0, MAXC)

    #
    # end data validation
    #####################################################


    #####################################################
    # output test case with print(..., file=outfile) here
    #

    print(len(c), file=outfile)
    print(*c, file=outfile)

    #
    # end of test case output
    #####################################################

    outfile.close()

    print("Generated", filename)

def gensample():
    genfile("sample", [7, 1, 2, 1, 5])
    genfile("sample", [7, 1, 3, 1, 5])
    genfile("sample", [4, 2, 3])

def scramble(l):
    random.shuffle(l)
    return l

def genhand():
    genfile("hand", [0])
    genfile("hand", [1])
    genfile("hand", [2])
    genfile("hand", [MAXC])
    genfile("hand", [0]*(MAXN//10))
    genfile("hand", [MAXC]*(MAXN//10))
    genfile("hand", [1]*10)
    genfile("hand", [2]*10)
    genfile("hand", [0]*20 + [1] + [0]*20)
    genfile("hand", scramble(list(range(MAXN, 0, -1))))
    genfile("hand", scramble(list(range(2*MAXN, MAXN, -1))))

def genrandom():
    sizes = [10, 10, 10]*3 + [100]*3 + [1000]*3 + [MAXN]*5

    for s in sizes:
        genfile("random", [random.randint(0, 2*s) for i in range(s)])

if __name__ == "__main__":
    random.seed(0)

    gensample()
    genhand()
    genrandom()

    print("Done!")
