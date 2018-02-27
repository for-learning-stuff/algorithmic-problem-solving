import random
import string

f = open("test.txt", "w") #relative to curr directory

def genString(l):
    w = ''.join(random.choice("abc") for _ in range(l))
    return w

def genNum(n):
    return random.randint(0,n)+1

MAXN = 10
MAXL = 10
MAXQ = 10
n = genNum(MAXN)
q = genNum(MAXQ)

lines = []
lines.append(str(n))


for i in range(n):
    lines.append(genString(genNum(MAXL)) + " " + str(genNum(10)))

lines.append(str(q))

for i in range(q):
    x = genString(genNum(4)) + ('#' if random.randint(0,1) else '')
    lines.append(x)

f.write("\n".join(lines))