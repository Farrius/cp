from jutge import read
from PIL import Image, ImageDraw

n, m = read(int, int)

mat = [[0 for j in range(m)] for i in range(n)]

sti = 0
stj = 0
eni = 0
enj = 0

for i in range(n):
    s = read(str)
    for j in range(m):
        mat[j][i] = s[j]
        if (s[j] == 'E'):
            sti = i
            stj = j
        if (s[j] == 'S'):
            eni = i
            enj = j

lo = 0
hi = 10000

cami = list()

def check (tapa):
    global cami
    global mat
    cami = list()
    vis = [[0 for j in range(m)] for i in range(n)]



sol = list()
while lo <= hi:
    mid = lo + (hi - lo)//2
    if (check(mid)):
        sol = cami
        hi = mid - 1
    else:
        lo = mid + 1

